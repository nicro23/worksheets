#include<iostream>
using namespace std;

void main()
{
    int nb, tb, nd, epd, cst , ct, max, pos;
    ct = 0;
    max = -9999;
    for(int i =1; i<=2000; i++)
    {
        cin>>nb>>tb>>nd>>epd;
        if(tb == 1)
        {
            cst = nb*1.5 + nd*epd;
        }
        if(tb == 2)
        {
            cst = nb*1.7 + nd*epd;
            ct++;
        }
        
        if(cst>max)
        {
            max = cst;
            pos = i;
        }
    }
    cout<<ct<<endl<<pos;
}