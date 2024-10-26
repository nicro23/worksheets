#include<iostream>
using namespace std;

class node
{
    public:
    int val;
    node* next;
};

class list
{
    public:
    node* head;
    node* tail;
    //tmm? constructor, attach, destructor
    list()
    {
        head = NULL;
        tail = NULL;
    }
    void attach(node* pnn) //&?
    {
        if(head == NULL)
        {
            head = pnn;
            tail = pnn;
        }
        else
        {
            tail->next = pnn;
            tail = pnn;
        }
    }
    ~list() //idk
    {
        node* trav = head;
        while(trav != NULL)
        {
            head = head->next;
            delete[] trav;
            trav = head;
        }
    }   
};
//for debugging
void disp(list x)
{
    node* trav = x.head;
    while(trav != NULL)
    {
        cout << trav->val<<" ";     
        trav = trav->next;
    }
    cout<<endl;
}



void main()
{
    list x;
    int n;
    node* pnn = NULL;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        pnn = new node;
        cin>>pnn->val;
        pnn->next = NULL;
        x.attach(pnn);
    }
    node* ptrav = x.head;
    int min = 999, max = -999;
    node* pmin = NULL;
    node* pmax = NULL;
    list x2;
    while(ptrav != NULL)
    {
        if(ptrav->val > max)
        {
            max = ptrav->val;
            pmax = ptrav;
        }
        if(ptrav->val < min)
        {
            min = ptrav->val;
            pmin = ptrav;
        }
        ptrav = ptrav->next;
    }
    while(pmin != pmax)
    {
        pnn = new node;
        pnn->val = pmin->val;
        pnn->next = NULL;
        x2.attach(pnn);   
        pmin = pmin->next;
    }
    pnn = new node;
    pnn->val = pmin->val;
    pnn->next = x2.head->next; 
    x2.head->next = pnn;
}