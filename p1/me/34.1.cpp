#include<iostream>
using namespace std;

void main()
{
    int ct, nk, gndr, age, dur, nj, ct, ctavg, max, max_prev, age_prev, jh;
    float tot;
    tot = 0;
    ct = 0;
    cin>>nk;
    for(int i =1; i<=nk; i++)
    {
        cin>>gndr>>age>>dur>>nj;
        if(gndr == 'b')
        {
            ctavg++;
            tot += dur;
        }
        max = -99999;
        for(int h = 1; h<=nj;h++)
        {
            cin>>jh;
            if(jh>max)
            {
                max = jh;
            }
        }
        if(age == age_prev && max == max_prev)
        {
            ct++;
        }
        max_prev= max;
        age_prev = age;
    }
    float avg = ctavg/ tot;
    cout<<avg<<endl<<ct;
}