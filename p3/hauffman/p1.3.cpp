#include<iostream>
#include<fstream>
using namespace std;

class node {
public:
    int f;
    char* code;
    char c;
    //max len of code is 255 take care
    unsigned char len_code;
    node* next;
    node* l;
    node* r;
    node()
    {
        f = 0;
        code = NULL;
        next = NULL;
        l = NULL;
        r = NULL;
    }
};

class slist {
public:
    node* head;
    //slist must include tail :"D
    node* tail;
    slist()
    {
        head = NULL;
    }
    void insert(node*& pnn)
    {
        if (head == NULL)
        {
            head = pnn;
        }
        else
        {
            node* trav = head;
            node* bk = NULL;
            while (trav != NULL)
            {
                if (pnn->f < trav->f)
                {
                    break;
                }
                bk = trav;
                trav = trav->next;
            }
            pnn->next = trav;
            if (bk == NULL)
            {
                head = pnn;
            }
            else
            {
                bk->next = pnn;
            }

        }
    }

    void rev_insert(node*& pnn)
    {
        if (head == NULL)
        {
            head = pnn;
        }
        else
        {
            node* trav = head;
            node* bk = NULL;
            while (trav != NULL)
            {
                if (pnn->f > trav->f)
                {
                    break;
                }
                bk = trav;
                trav = trav->next;
            }
            pnn->next = trav;
            if (bk == NULL)
            {
                head = pnn;
            }
            else
            {
                bk->next = pnn;
            }

        }
    }
    void disp()
    {
        node* trav = head;
        while (trav != NULL)
        {
            cout << "(" << trav->c << ",";
            cout << trav->code;
            cout << ") ";
            trav = trav->next;
        }
    }
    node* merge()
    {
        node* ntree = new node();
        node* ltemp = head;
        node* rtemp = head->next;
        head = head->next->next;
        ntree->f = ltemp->f + rtemp->f;
        ntree->l = ltemp;
        ntree->r = rtemp;
        ntree->next = NULL;
        ltemp->next = NULL;
        rtemp->next = NULL;
        return ntree;
    }
};

void merge_full_list(slist& s)
{
    node* trav = s.head;
    node* tmp = NULL;
    while (trav->next != NULL)
    {
        tmp = s.merge();
        s.insert(tmp);
        trav = s.head;
    }
}
void code_tree(node* curr, int i, char* code)
{
    if (curr == NULL)
    {
        return;
    }
    char* tmpcode_l = new char[i];
    char* tmpcode_r = new char[i];
    for (int j = 0; j < i - 2; j++)
    {
        tmpcode_l[j] = code[j];
        tmpcode_r[j] = code[j];
    }
    tmpcode_r[i - 2] = '0';
    tmpcode_l[i - 2] = '1';
    tmpcode_r[i - 1] = '\0';
    tmpcode_l[i - 1] = '\0';
    code_tree(curr->r, ++i, tmpcode_l);
    code_tree(curr->l, i, tmpcode_r);
    if (curr->r == NULL)
    {
        curr->code = code;
        curr->len_code = i - 3;
        if((i - 3) > 255)
        {
            curr->code = new char[9];
            curr->code[0] = 'c';curr->code[1] = 'o';curr->code[2] = 'd';curr->code[3] = 'e';
            curr->code[4] = 'l';curr->code[5] = 'o';curr->code[6] = 'n';curr->code[7] = 'g';
            curr->code[8] = '\0';
        }
    }
}
void disp_tree(node* curr, int ct)
{
    if (curr == NULL)
    {
        return;
    }
    disp_tree(curr->r, ct++);
    disp_tree(curr->l, ct);
    if (curr->r == NULL)
    {
        cout << "(" << curr->c << ",";
        cout << curr->f << " " << curr->code;
        cout << ") " << endl;
    }
}

void tree_to_list(node* curr,node* bk, slist& l)
{
    if(curr == NULL)
    {
        return;
    }
    tree_to_list(curr->r, curr, l);
    tree_to_list(curr->l, curr, l);
    if(curr->r == NULL)
    {
        if(bk->r == curr)
        {
            bk->r = NULL;
        }
        else
        {
            bk->l = NULL;
        }
        l.rev_insert(curr);
    }
}

void nxt()
{
    cout<< endl<< "step completed"<< endl;
}

node* find_letter(char c, slist& l)
{
    node* trav = l.head;
    while(trav != NULL)
    {
        if(trav->c == c)
        {
            break;
        }
        trav = trav->next;
    }
    return trav;
}

node* find_code(char cmp[],int len, slist& l)
{
    node* trav = l.head;
    int f;
    while(trav != NULL)
    {
        if(len == trav->len_code)
        {
            f = 1;
            for(int i = 0; cmp[i] != '\0'; i++)
            {
                if( cmp[i] != trav->code[i])
                {
                    f = 0;
                }
            }
            if(f == 1)
            {
//                cout << cmp << "|||" << trav->code <<" "<< trav->c<< endl;
                break;
            }
        }
        trav = trav->next;
    }
    return trav;
}

int main()
{
    //declare & initialize var
    slist l;
    node* n;
    //max len_code is 255
    char cmp[255];
    char c, code, mask;
    ifstream f;
    ofstream o;
    int len, bits_written, len_code, num_node;

    //read code list
    f.open("meta.txt", ifstream::binary);
    f.seekg(0, f.end);
    len = f.tellg();
    f.seekg(0, f.beg);

    for(int i = 0; i < len;)
    {
        f.read(&c, 1);
        i++;
        n = new node();
        n->c = c;
        f.read(&c, 1);
        i++;
        n->len_code = c;
        len_code = c;
        n->code = new char[len_code];
        f.read(&c, 1);
        i++;
        bits_written = 0;
        for(int j = 0; j < len_code - 1; j++)
        {
            mask = 1;
            mask = mask << (7 - bits_written);
            code = c & mask;
            bits_written++;
            if(code == 0)
            {
                n->code[j] = '0';
            }
            else
            {
                n->code[j] = '1';
            }
            n->code[j + 1] = '\0';
            if(bits_written == 8)
            {
                f.read(&c, 1);
                i++;
                bits_written = 0;
            }
        }
        l.rev_insert(n);
    }
    l.disp();
    nxt();

    f.close();
    f.open("compressed.bin", ifstream::binary);
    o.open("out.bin", ofstream::binary);
    f.seekg(0, f.end);
    len = f.tellg();
    f.seekg(0, f.beg);
    bits_written = 0;
    for(int i = 0; i < len - 2; i++)
    {
        f.read(&c, 1);
        for(int j = 0; j < 8; j++)
        {
            mask = 1;
            mask = mask << (7 - j);
            code = c & mask;
            if(code == 0)
            {
                cmp[bits_written++] = '0';
            }
            else
            {
                cmp[bits_written++] = '1';
            }
            cmp[bits_written + 1] = '\0';
            n = find_code(cmp, bits_written + 1, l);
            if(n != NULL)
            {
                code = n->c;
                o.write(&code, 1);
                bits_written = 0;
            }
        }
    }
    //read last byte
    f.read(&c, 1);
    len = c;
    f.read(&c, 1);
    for(int j = 0; j < len; j++)
    {
        mask = 1;
        mask = mask << (7 - j);
        code = c & mask;
        if(code == 0)
        {
            cmp[bits_written++] = '0';
        }
        else
        {
            cmp[bits_written++] = '1';
        }
        cmp[bits_written + 1] = '\0';
        n = find_code(cmp, bits_written + 1, l);
        if(n != NULL)
        {
            code = n->c;
            o.write(&code, 1);
            bits_written = 0;
        }
    }
    nxt();
}

