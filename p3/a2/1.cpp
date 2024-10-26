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
        cout<<trav->val<<" ";
        trav = trav->next;
    }
    cout<<endl;
}

void SplitList_1(list MainList,int SplitVal,list List1,list List2)
{
    node* trav = MainList.head;
    node* temp = NULL;
    while(trav->val != SplitVal)
    {
        temp = new node;
        temp->val = trav->val;
        temp->next = NULL;
        List1.attach(temp);
        trav = trav->next;
    }
    while(trav != NULL)
    {
        temp = new node;
        temp->val = trav->val;
        temp->next = NULL;
        List1.attach(temp);
        List2.attach(trav);
        trav = trav->next;
    }
}

void SplitList_2(list MainList,int SplitVal,list List1,list List2)
{
    node* trav = MainList.head;
    // node* bk = NULL;
    while(trav->next->val != SplitVal)
    {
        // bk = trav;
        trav = trav->next;
    }
    //assign the heads and tails
    List1.head = MainList.head;
    List1.tail = trav;
    List2.head = trav->next;
    List2.tail = MainList.tail;
    //"split the lists"
    trav->next = NULL;
    //"delete original list"
    MainList.head = NULL;
    MainList.tail = NULL;
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
}