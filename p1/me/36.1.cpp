#include<iostream>
using namespace std;

void main()
{
    int nr, nd, t1, t2, t3, ct, max, pos;
    max= -99999;
    ct = 0;
    cin>>nr;
    for(int i= 1; i<=nr;i++)
    {
        cin>>nd;
        for(int j=1;j<=nd;j++)
        {
            cin>>t1>>t2>>t3;
            if(i == 5)
            {
                if(t3>0 && t2==0 && t1 == 0)
                {
                    ct++;
                }
            }
        }
        if(nd>max)
        {
            max = nd;
            pos = i;
        }
    }
    cout<<pos<<endl<<ct;
}