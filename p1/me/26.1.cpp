#include<iostream>
using namespace std;

void main()
{
    int n, tot, d, max, area, amount_wtr, tmp, slt, ct, avg;
    cin>>n;
    tot= 0;
    ct = 0;
    max = 9999999;
    for(int i =1 ;i<=n; i++)
    {
        cin>>area;
        for(d = 1 ; ;d++)
        {
            cin>>amount_wtr>>tmp;
            if(amount_wtr==0)
            {
                break;
            }
        }
        if(d>max)
        {
            max = d;
        }
        cin>>slt;
        if(area>20)
        {
            tot += slt;
            ct++;
        }
    }
    avg = tot/ct;
    cout<<avg<<max;
}