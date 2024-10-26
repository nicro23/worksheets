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
    int n;
    cin >> n;
    read(head, tail, n);
    int v;
    cin >> v;
    list* tmp = head;
    while (tmp != NULL)
    {
        if (tmp->next->next->next->val == v)
        {
            break;
        }
        tmp = tmp->next;
    }
    int total = 0;
    for (int i = 0; i < 7; i++, tmp = tmp->next)
    {
        total += tmp->val;
        if (i == 3)
        {
            total -= tmp->val;
        }
    }
    cout << total;
}