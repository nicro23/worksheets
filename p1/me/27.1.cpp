#include<iostream>
using namespace std;

void main()
{
    int ct_avg, ct, i, j, n, nb, nh, tp, wt, br;
    float tot_avg, avg;
    char tp;
    cin>>n;
    ct =0;
    for(i = 1;i<=n;i++)
    {
        ct_avg =0;
        tot_avg=0;
        cin>>nb>>nh;
        for(j=1;j<=nh;j++)
        {
            cin>>tp>>wt;
            if(tp == 'b')
            {
                ct_avg++;
                tot_avg+= wt;
            }
        }
        avg = tot_avg/ct_avg;
        cin>>br;
        if(br<nb*0.5)
        {
            ct++;
        }
        cout<<avg;
    }   
    cout<<ct;
}