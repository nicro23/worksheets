#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
using namespace std;

class node {
public:
    int f;
    char* code;
    char* c;
    node* next;
    node* l;
    node* r;
    node()
    {
        f = 0;
        code = NULL;
        c = NULL;
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
    void attach(node*& pnn)
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
    void disp()
    {
        node* trav = head;
        while (trav != NULL)
        {
            cout << "(" << trav->f << ",";
            if (trav->c != NULL)
            {
                cout << trav->c;
            }
            cout << ") ";
            trav = trav->next;
        }
    }
    void merge()
    {
        node* ntree = new node();
        node* ltemp = head;
        node* rtemp = head->next;
        ntree->f = ltemp->f + rtemp->f;
        ntree->l = ltemp;
        ntree->r = rtemp;
        ntree->next = rtemp->next;
        head = ntree;
        ltemp->next = NULL;
        rtemp->next = NULL;
    }
};

void merge_full_list(slist& s)
{
    node* trav = s.head;
    while (trav->next != NULL)
    {
        s.merge();
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
    code_tree(curr->r, i++, tmpcode_r);
    code_tree(curr->l, i, tmpcode_l);
    if (curr->r == NULL)
    {
        curr->code = code;
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
        cout << "(" << curr->f << ",";
        if (curr->c != NULL)
        {
            cout << curr->c << " " << curr->code;
        }
        cout << ") " << endl;
    }
}
int main()
{
    slist s;
    node* n;
    int freq[255];
    char c;
    ifstream f;
    string temp;
    char* line = NULL;
    int len;

    for (int i = 0; i < 255; i++)
    {
        freq[i] = 0;
    }

    f.open("test.txt");
    while (getline(f, temp))
    {
        len = temp.length();
        line = new char[len];
        for (int i = 0; i < len; i++)
        {
            line[i] = temp[i];
        }
        //is this okay?
        for (int i = 0; line[i] != '\0'; i++)
        {
            int j = line[i];
            freq[j]++;
        }
    }

    c = 0;
    for (int i = 0; i < 255; i++)
    {
        n = new node();
        n->c = new char[2];
        n->c[0] = c++;
        n->c[1] = '\0';
        n->f = freq[i];
        if (n->f)
        {
            s.attach(n);
        }
    }

    s.disp();
    merge_full_list(s);
    cout << endl;
    s.disp();
    cout << endl;
    code_tree(s.head, 2, NULL);
    disp_tree(s.head, 0);
}
