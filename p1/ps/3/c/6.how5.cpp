#include<iostream>
using namespace std;

void main()
{
    int n, hu, te, u, ct;
    ct = 0;
    cin>>n;
    if(n>99 && n<1000)
    {
        hu = n/100;
        te = (n%100)/10;
        u = n%10;
        if(hu>5)
        {
            ct++;
        }
        if(te>5)
        {
            ct++;
        }
        if(u>5)
        {
            ct++;
        }
        cout<<ct;
    }
    else
    {
        cout<<"error";
    }
}