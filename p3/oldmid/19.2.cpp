#include<iostream>
using namespace std;
#define tull (trav != NULL)
#define text trav->next
#define ttext trav = trav->next
#define tnfo trav->info

class cnode
{
public:
  int info;
  cnode* next;
  //
  cnode* down;
};

class clist
{
public:
  cnode* head;
  cnode* tail;
  //
  cnode* up;
  clist()
  {
    head = NULL;
    tail = NULL;
  }
  void attach(cnode* pnn)
  {
    if(head == NULL)
    {
      head = pnn;
      tail = pnn;
    }
    else {
      tail->next = pnn;
      tail = pnn;
      tail->next = NULL;
    }
  }
  void disp()
  {
    cnode* trav = head;
    while(tull)
    {
      cout<<tnfo<<" ";
      ttext;
    }
    cout<<endl;
  }
  ~clist()
  {
    if(head != NULL) {
      cnode *trav = head->next;

      while (tull) {
        head->next = text;
        text = NULL;
        //      delete trav;
        trav = head->next;
      }
    }
  }
};

class stack
{
public:
  cnode* head;

  stack()
  {
    head = NULL;
  }

  void push(cnode* pnn)
  {
      pnn->next = head;
      head = pnn;
  }
  cnode* pop()
  {
    cnode* trav = head;
    head = head->next;
    text = NULL;
    return trav;
  }
  void disp()
  {
    cnode* trav = head;
    while(tull)
    {
      cout<<tnfo<<" ";
      ttext;
    }
    cout<<endl;
  }
  ~stack()
  {
    cnode* trav = head;
    while(tull)
    {
      head = head->next;
      text = NULL;
//      delete trav;
      trav = head;
    }
  }
};

int main()
{
    cnode* nn = NULL;
    clist l[30];
    stack s;
    int n, v, start, f = 0;
    cnode* zero = NULL;
    cin>>n;
    cnode* bk = NULL;
    cnode* trav = NULL;
    for(int k = 0; k<3;k++) {
        if(k>0)
        {
          trav = l[k - 1].head;
        }
        for (int i = 0; i < n; i++) {
          nn = new cnode[1];
          cin >> v;
          nn->info = v;
          nn->next = NULL;
          nn->down = NULL;
          l[k].attach(nn);
          if(k>0)
          {
              if(tnfo == 0)
              {
                  trav->down = l[k].tail;
                  l[k].tail->down = bk;
              }
              ttext;
          }
          bk = l[k].tail;
        }
    }

    int index;
    cin>>index;
    clist nl;
    trav = l[index].head;
    while(tull)
    {
        if(trav->info != 0)
        {
            bk = trav;
        }
        else
        {
            if (trav->next->info != 0) {
                break;
            }
        }
        text;
    }
    nl.head = bk->next;
    bk->next->down->down->next = trav->down->next;
    bk->next = trav->next;
    trav->next = nl.head->down;
    nl.tail = trav->down;
    nl.tail->next = NULL;
    bk = nl.head;
    trav = nl.head->next;
    while(tull)
    {
        trav->down = bk;
        bk = trav;
        ttext;
    }
    nl.disp();
}

9
14
32
0
0
41
20
30
49
42
37
15
23
43
44
28
0
0
24
21
29
0
0
38
13
22
46
12
1