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
            delete trav;
            trav = head;
            }
        }
};
//for debugging
void disp(list& x)
{
    node* trav = x.head;
    while(trav != NULL)
    {
        cout<<trav->val<<" ";
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
    cin>>n;
    x.tail->next = x.head;
    for(int i = 0; i < n; i++)
    {
        x.head = x.head->next;
        x.tail = x.tail->next;
    }
    x.tail->next = NULL;
    //test
    //  disp(x);
}