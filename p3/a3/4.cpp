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

void neg(list& l, list& nl)
{
    node* start = NULL;
    node* end = NULL;
    node* trav = l.head;
    while (trav != NULL)

        if (trav->next != NULL)
        {
            if (trav->next->val < 0)
            {
                start = trav;
                end = trav->next->next;
                while (1)
                {
                    if (end->val < 0)
                    {
                        if (nl.head == NULL)
                        {
                            nl.head = start->next;
                        }
                        else
                        {
                            nl.tail->next = start->next;
                        }
                        start->next = end->next;
                        end->next = NULL;
                        nl.tail = end;
                        break;
                    }
                    end = end->next;
                }
            }
            trav = trav->next;
        }
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
    list nl;
    int j = 2 - 1;
    for (int i = 0; i < 2 / 2; i++, j--)
    {
        neg(l[i], nl);
        neg(l[j], nl);
    }
    disp(nl);
    //disp test:
    for (int i = 0; i < 2; i++)
    {
        disp(l[i]);
    }

}