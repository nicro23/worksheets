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

class node_list {
public:
    int f;
    char* code;
    char* c;
    node_list* next;
    node_list* down;
    node_list()
    {
        f = 0;
        code = NULL;
        c = NULL;
        next = NULL;
        down = NULL;
    }
};

class node_tree {
    int f;
    char* code;
    char* c;
    node_tree* left;
    node_tree* right;
    node_tree()
    {
        f = 0;
        code = NULL;
        c = NULL;
        left = NULL;
        right = NULL;
    }
};
//class slistl {
//public:
//    node_list* head;
//    node_list* tail;
//    slistl()
//    {
//        head = NULL;
//        tail = NULL;
//    }
//    void insert(node_list*& pnn)
//    {
//        if (head == NULL)
//        {
//            head = pnn;
//        }
//        else
//        {
//            node_list* trav = head;
//            node_list* bk = NULL;
//            while (trav != NULL)
//            {
//                if (pnn->f < trav->f)
//                {
//                    break;
//                }
//                bk = trav;
//                trav = trav->next;
//            }
//            pnn->next = trav;
//            if (bk == NULL)
//            {
//                head = pnn;
//            }
//            else
//            {
//                bk->next = pnn;
//            }
//
//        }
//    }
//    void r_insert(node_list*& pnn)
//    {
//        if (head == NULL)
//        {
//            head = pnn;
//        }
//        else
//        {
//            node_list* trav = head;
//            node_list* bk = NULL;
//            while (trav != NULL)
//            {
//                if (pnn->f > trav->f)
//                {
//                    break;
//                }
//                bk = trav;
//                trav = trav->next;
//            }
//            pnn->next = trav;
//            if (bk == NULL)
//            {
//                head = pnn;
//            }
//            else
//            {
//                bk->next = pnn;
//            }
//
//        }
//    }
//    void disp()
//    {
//        node_list* trav = head;
//        while (trav != NULL)
//        {
//            cout << "(" << trav->f << ",";
//            if (trav->c != NULL)
//            {
//                cout << trav->c;
//            }
//            cout << ") ";
//            trav = trav->next;
//        }
//    }
//    /*node_* tree_cnvrt()
//    {
//        node_tree* ntree = new node_tree();
//        node_list* ltemp = head;
//        node_list* rtemp = head->next;
//        head = head->next->next;
//        ntree->f = ltemp->f + rtemp->f;
//        ntree->l = ltemp;
//        ntree->r = rtemp;
//        ntree->next = NULL;
//        ltemp->next = NULL;
//        rtemp->next = NULL;
//        return ntree;
//    }*/
//
//};

class slist {
public:
    node* head;
    //slist must include tail :"D
    node* tail;
    slist()
    {
        head = NULL;
        tail = NULL;
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
    ~slist()
    {
        delete[] head;
    }
};
void merge_full_list(slist& s)
{
    node* trav = s.head;
    node* tmp = NULL;
    while (trav->next != NULL)
    {
        node* tmp = s.merge();
        s.attach(tmp);
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

void tree_to_list(node* curr, slist& list)
{
    if (curr == NULL)
    {
        return;
    }
    tree_to_list(curr->r, list);
    tree_to_list(curr->l, list);
    if (curr->r != NULL && curr->c != NULL)
    {
        node* tmp = new node();
        tmp->c = curr->c;
        tmp->code = curr->code;
        tmp->next = NULL;
        tmp->r = NULL;
        tmp->l = NULL;
        list.attach(tmp);
    }
}

int main()
{
    slist s;
    node* n;
    //slistl out_code;
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
            //char to int
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
    //tree_to_list(s.head, out_code);
}
// out linked list
// read using seek
// batats m7mra