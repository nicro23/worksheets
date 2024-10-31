#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* next;
};
class list {
public:
    node* head;
    node* tail;

    list()
    {
        head = NULL;
        tail = NULL;
    }

    void attach(node* n)
    {
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }

    ~list()
    {
        node* trav = head;
        while (trav != NULL)
        {
            head = head->next;
            delete trav;
            trav = head;
        }
    }
};

void disp(list& l)
{
    node* trav = l.head;
    while (trav != NULL)
    {
        cout << trav->val<<" ";
        trav = trav->next;
    }
    cout << endl;
}
int main()
{
    list l1, l2;
    node* temp = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        temp = new node;
        cin >> temp->val;
        temp->next = NULL;
        l1.attach(temp);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        temp = new node;
        cin >> temp->val;
        temp->next = NULL;
        l2.attach(temp);
    }
    node* trav1 = l1.head;
    node* trav2 = l2.head;
    node* bk = trav2;
    while (trav1 != NULL)
    {
        if (trav1->val == trav2->val)
        {
            bk->next = trav2->next;
            trav2->next = NULL;
            delete trav2;
            trav2 = bk->next;
        }
        else
        {
            bk = trav2;
            trav2 = trav2->next;
        }
        trav1 = trav1->next;
    }
    //debugging:
    //  disp(l1);
    //  disp(l2);
}