#include<iostream>
using namespace std;

void main()
{
    float i, n, ds, s, ds, dis, ct, cta, tot, min, avg;
    ct = 0;
    tot = 0;
    cta = 0;
    min = 99999;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>dis>>s>>ds;
        if(ds == 2)
        {
            ct++;
        }
        if(ds == 3)
        {
            tot+= s;
            cta++;
        }
        if(ds == 1 && dis<min)
        {
            min = dis;
        }

    }
    avg =  tot/cta;
    cout<<ct<<endl<<avg<<endl<<min;
}