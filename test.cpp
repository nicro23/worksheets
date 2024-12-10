#include<iostream>
using namespace std;

class cnode
{
    int n;
    cnode* next;
};

//last = null
void rec(cnode* ptrav,cnode* pback, cnode* &plast, cnode* &pfirst, int &ct, int v1, int v2)
{
    if(pback->n == v1 || pback->n == v2)
    {
        ct++;
        pfirst = pback;
    }
    if(ptrav->n == v1 || ptrav->n == v2 && ct == 1)
    {
        pfirst->next = pback;
        plast = ptrav;
        return;
    }

    rec(ptrav->next, pback->next, plast);
    if(pback->next == v1 || pback->next == v2)
    {
        ct++;
    }
    if(ct==2)
    ptrav->next = pback;

}