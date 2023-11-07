#include<iostream>
using namespace std;

void main()
{
    int n, i, ct;
    cin>>n;
    ct = 0;
    for(i=1;i<n; i++)
    {
        if(n%i == 0)
        {
            cout<< i<<" ";
            ct++;
        }
    }
    cout<<endl<<ct;
}