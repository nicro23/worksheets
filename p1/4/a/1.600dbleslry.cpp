#include<iostream>
using namespace std;

void main()
{
    int s, r, c, ct;
    ct = 0;
    for(int i = 1;i<600;i++)
    {
        cin>>s>>r>>c;
        if(s > (r+c)*2)
        {
            ct++;
        }

    }
    cout<<ct;
}