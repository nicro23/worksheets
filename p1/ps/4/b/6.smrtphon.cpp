#include<iostream>
using namespace std;

void main ()
{
    int tp, iftp, ms, cst, ct, min, pos; 
    ct= 0;
    min = 9999;
    for(int i=1; i<= 3000;i++)
    {
        cin>>tp>>iftp>>ms;
        cst=0;
        if(tp == 1)
        {
            cst+= 1500;
        }
        else
        {
            cst+= 2300;
        }
        if(iftp == 1)
        {
            cst+= 80;
            ct++;
        }
        cst+= ms*10;
        if(cst<min)
        {
            min = cst;
            pos = i;
        }
    }
    cout<<ct<<endl<<pos;
}