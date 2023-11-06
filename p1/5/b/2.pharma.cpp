#include<iostream>
using namespace std;

void main()
{
    int nd, min, prev_c, tot_vc, tot_age, ct_age, ct_suc, vc, age, vd, c, nc, pos, avg_age;
    cin>>nd;
    min = -99999;
    prev_c=0;
    for(int d = 1; d<=nd; d++)
    {
        tot_vc = 0;
        tot_age = 0;
        ct_age = 0;
        cin>>nc;
        if( prev_c == c)
        {
            ct_suc++;
        }
        prev_c = nc;
        for(int c =1; c<=nc; c++)
        {
            cin>>age>>vc>>vd;
            tot_vc+= vc;
            if(vc >1)
            {
                tot_age += age;
                ct_age++;
            }
        }
        if(tot_vc< min)
        {
            min = tot_vc;
            pos = d;
        }
        avg_age = tot_age/ct_age;
        cout<<avg_age<<endl;    
    }
    cout<<pos<<endl<<ct_suc;
}