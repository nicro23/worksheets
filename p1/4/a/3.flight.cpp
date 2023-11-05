#include<iostream>
using namespace std;

void main()
{
    int p, ntc, m, min, ct;
    ct=0;
    min=9999;
    for(int i=1; i<=5000; i++)
    {
        cin>>p>>ntc>>m;
        if(m==3 && p<min)
        {
            min = p;
        }
        if(ntc==0)
        {
            ct++;
        }
    }
    cout<<min<<endl<<ct;
}