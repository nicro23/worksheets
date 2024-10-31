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

void ReverseList(list &MainList)
{
    node* one = MainList.head;
    MainList.head = one->next;
    node* three  = one->next->next;
    MainList.tail = one; //the new tail
    MainList.tail->next = NULL; // nullify the end
    while(three != NULL)
    {
        MainList.head->next = one;
        one = MainList.head;
        MainList.head = three;
        three = three->next;
    }
    MainList.head->next = one;
}

void ReverseList(list &MainList, list &List1)
{
    node* t_tmp = MainList.tail;
    node* trav = MainList.head;
    node* temp = NULL;

    while(t_tmp != MainList.head)
    {
        trav = MainList.head;
        while(trav->next != t_tmp)
        {
        trav = trav->next;
        }
        temp = new node;
        temp->val = t_tmp->val;
        temp->next = NULL;
        List1.attach(temp);
        t_tmp = trav;
    }
    temp = new node;
    temp->val = t_tmp->val;
    temp->next = NULL;
    List1.attach(temp);
    /* T-T refused
    while(trav != NULL)
    {
        temp = new node;
        temp->val = trav->val;
        temp->next = NULL;
        if(List1.tail == NULL)
        {
            List1.tail = temp;
            List1.head = temp;
        }
        else
        {
            temp->next = List1.tail;
            List1.tail = temp;
        }
        trav = trav->next;
    }*/
    /* :( also refused
        node* trav = MainList.head;
        while(trav != NULL)
        {
            List1.attach(trav);
            trav = trav->next;
        }
        ReverseList(List1);
    */
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

    /*
    test 1:
        disp(x);
        ReverseList(x);
        disp(x);
    */
    /*
    test 2:
        list y;
        ReverseList(x,y);
        disp(x);
        disp(y);
    */

    }