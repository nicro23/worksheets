#include<iostream>
using namespace std;

void main()
{
    int n, v, cmp, i, ct;
    cin>>n;
    ct = 0;
    for(i =1;i<=n;i++)
    {
        cin>>v;
        if(i == 1)
        {
            cmp = v%1000;
        }
        if(i>1)
        {
            if( v > cmp)
            {
                ct++;
            }
        }
    }
    cout<<ct;
}