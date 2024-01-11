#include<iostream>
using namespace std;

void main()
{
    float i, n, dc, fupv, hos, age, tot, cta, ct, avg;
    ct = 0;
    cta = 0;
    tot = 0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>dc>>fupv>>hos>>age;
        if(age<20)
        {
            tot+= (dc + fupv + hos);
            cta++;
        }
        if(fupv>dc)
        {
            ct++;
        }
    }
    avg = tot/cta;
    cout<<avg<<endl<<ct;
}