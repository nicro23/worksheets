#include<iostream>
using namespace std;

class list
{
public:
    int val;
    list* next;
};
void read(list* &head, list* &tail, int n)
{
    list* tmp;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        tmp = new list;
        tmp->val = val;
        tmp->next = NULL;
        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }
}
void main()
{
    list* head = NULL;
    list* tail = NULL;
    list* head2 = NULL;
    list* tail2 = NULL;
    int n;
    cin >> n;
    read(head, tail, n);
    cin >> n;
    read(head2, tail2, n);
    list* tmp = head;
    list* tmp2 = head2;
    int ct = 0;
    while (tmp != NULL)
    {
        if (tmp->val == tmp2->val)
        {
            cout << '[' << ct << ',' << tmp->val << "], ";
        }
        tmp = tmp->next;
        tmp2 = tmp2->next;
        ct++;
    }
    
}