#include<iostream>
using namespace std;

void main()
{
    float w, h, ct, min, cta, tot, avg;
    ct = 0;
    min =99999;
    tot= 0;
    cta = 0;
    for(int i=1; i<=3000; i++)
    {
        cin>>w>>h;
        if(w<min)
        {
            min = w;
        }
        if(w<=(h-110))
        {
            ct++;
        }
        if(w>(h-110))
        {
            tot+= w;
            cta++;
        }
    }
    avg = tot/cta;
    cout<<min<<endl<<ct<<endl<<avg;

}