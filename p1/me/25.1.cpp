#include<iostream>
using namespace std;

void main()
{
    int n, i, ct, tot, j, dur, wt_bef, wt_aftr;
    cin>>n;
    for( i =1; i<=n;i++)
    {
        ct = 0;
        tot = 0;
        cin>>wt_bef;
        for( j=1;j<=35;j++)
        {
            cin>>dur;
            if(dur > 0)
            {
                ct++;
            }
            tot+= dur;
        }
        cout<<ct;
        cin>>wt_aftr;
        if((wt_bef - wt_aftr)>800)
        {
            cout<<tot;
        }
    }
}