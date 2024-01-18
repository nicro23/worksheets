#include<iostream>
using namespace std;

void main()
{
    int nd, min, prev_c, tot_vd, tot_age, ct_age, ct_suc, vc, age, vd, c, nc, pos, avg_age;
    cin>>nd;
    min = -99999;
    prev_c=0;
    ct_suc = 0;
    for(int d = 1; d<=nd; d++)
    {
        tot_vd = 0;
        tot_age = 0;
        ct_age = 0;
        cin>>nc;
        if( prev_c == nc)
        {
            ct_suc++;
        }
        prev_c = nc;
        for(int c =1; c<=nc; c++)
        {
            cin>>age>>vc>>vd;
            tot_vd+= vd;
            if(vc >= 1 && vd == 0)
            {
                tot_age += age;
                ct_age++;
            }
        }
        if(tot_vd< min)
        {
            min = tot_vd;
            pos = d;
        }
        avg_age = tot_age/ct_age;
        cout<<avg_age<<endl;    
    }
    cout<<pos<<endl<<ct_suc;
}