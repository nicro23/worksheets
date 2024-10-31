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
        cout << trav->val << " ";
        trav = trav->next;
    }
    cout << endl;
}

int main()
{
    list l[30];
    int n;
    node* tmp = NULL;
    for (int i = 0; i < 30; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            tmp = new node;
            cin >> tmp->val;
            tmp->next = NULL;
            l[i].attach(tmp);
        }
    }

    //assume negative values cant be first or last + list 1 is bigger than list 2
    for (int i = 0; i < 30 / 2; i++)
    {
        node* trav1 = l[i].head;
        node* trav2 = l[i + 1].head;
        node* back2 = NULL;
        while(trav1 != NULL)
        {
            if (trav1->val == -1)
            {
                back2->next = trav2->next;
                trav2->next = trav1->next;
                trav1->next = trav2;
                trav2 = back2;
                trav1 = trav1->next;
            }
            trav1 = trav1->next;
            back2 = trav2;
            trav2 = trav2->next;
        }
    }
    /* 
    test:
        disp(l[0]);
        disp(l[1]);
    */

}