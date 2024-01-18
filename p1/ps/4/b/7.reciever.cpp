#include<iostream>
using namespace std;

void main()
{
    int n, min, ct, td, tr, nm, cst, pos;
    cin>>n;
    min = 99999;
    ct = 0;
    for(int i=1;i<n;i++)
    {
        cin>>td>>tr>>nm;
        cst = 0;
        if(td == 1)
        {
            cst+= 50;
        }
        else
        {
            if(td == 2)
            {
                cst+=150;
            }
            else
            {
                cst+=200;
            }
        }
        if(tr == 1)
        {
            cst+= 500;
        }
        else
        {
            if(tr == 2)
            {
                cst+=650;
            }
            else
            {
                cst+=800;
            }
        }
        cst+= nm*3;
        if(cst<min)
        {
            min = cst;
            pos = i;
        }
        if(nm<20)
        {
            ct++;
        }
    }
    cout<<pos<<endl<<ct;
}