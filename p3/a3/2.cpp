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
    node* p1 = l1.head;
    node* p2 = l1.head->next;
    while(p2 != NULL)
    {
        int tot = 0;
        node* trav = l2.head;
        while (trav->val != p1->val)
        {
            trav = trav->next;
        }
        trav =  trav->next;
        while (trav->val != p2->val)
        {
            tot += trav->val;
            trav = trav->next;
        }
        cout << "total between " << p1->val << "&" << p2->val<<": "<<tot<<endl;
        if (p2->next != NULL)
        {
            p1 = p1->next->next;
            p2 = p2->next->next;
        }
        else
        {
            p2 = p2->next;
        }
    }
}