#include<iostream>
using namespace std;

int main()
{
    int n1, n2, frst, scnd, thrd, frth, ct;
    cin>>n1>>n2;
    if(n1 < 100000 && n1 >9999 && n2>9 && n2<100)
    {
        frst = n1/10000;
        scnd = (n1 -((n1/100000)*100000)) / 1000;
        thrd = (n1%1000)/10;
        frth = n1%100;
        ct = 0;
        if(n2>frst)
        {
            ct++;
        }
        if(n2>scnd)
        {
            ct++;
        }
        if(n2>thrd)
        {
            ct++;
        }
        if(n2>frth)
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