#include<iostream>
using namespace std;

void main()
{
    int n, i, ct, max, age, gndr, pos, ct2, num_brwn, num_white;
    char gndr;
    cin>>n;
    ct = 0;
    max = -99999;
    for(i = 1; i<=n; i++)
    {
        ct2 = 0;
        cin>>num_white>>num_brwn;
        if(num_brwn>num_white)
        {
            ct++;
        }
        for(i =1 ; i<=(num_white+num_brwn);i++)
        {
            cin>>age>>gndr;
            if(gndr == 'f')
            {
                ct2++;
            } 
        }
        if( ct2>max)
        {
            max = ct2;
            pos = i;
        }
    }
    cout<<ct<<pos;
}