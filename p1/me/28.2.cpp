#include<iostream>
using namespace std;

void main()
{
    int n, i, v, difo, vo, dife, ve, z3lan=0;
    cin>>n;
    for(i =1;i<=n;i++)
    {
        cin>>v;
        if((i%2) != 0)
        {
            if(i>1)
            {
                difo = v - vo;
            }
            vo = v;
        }
        if((i%2) == 0)
        {
            if(i>3)
            {
                dife = v - ve;
            }
            ve = v;
        }
        if(i>3)
        {
            if(difo != dife)
            {
                z3lan = 1;
            }
        }
    }
    if(z3lan == 1)
    {
        cout<<"false";
    }
    else
    {
        cout<<"true";
    }
}