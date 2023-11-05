#include<iostream>
using namespace std;

void main()
{
    int dis, np, pp, ct ,max;
    int pos;
    ct = 0;
    max = -99999;
    for(int i=1;i<=5000;i++)
    {
        cin>>dis>>np>>pp;
        if(np>10)
        {
            ct++;
        }
        if((pp*np)>max)
        {
            max =(pp*np);
            pos=i;
        }
    }
    cout<<ct<<endl<<pos;
}