#include<iostream>
using namespace std;

void main()
{
    int tot_wp, nd, nc, dur, prc, wp, pos, max, tot_avg, tot_dur, ct_avg, avg, inc;
    cin>>nd;
    ct_avg = 0;
    tot_avg = 0;
    tot_wp = 0;
    for(int d= 1;d<=nd;d++)
    {
        inc = 0;
        tot_dur = 0;
        for(int c = 1;     ;c++)
        {           
            cin>>dur>>prc>>wp;
            inc+= prc;
            tot_wp += wp;
            tot_dur+= dur;
            if(dur>100)
            {
                ct_avg++;
                tot_avg+= prc;
            }
            if(tot_wp>max && tot_dur<90)
            {
                max = tot_wp;
                pos = d;
            }
             if(inc>200 || tot_dur>180)
            {
                break;
            }
        }
        avg = tot_avg/ct_avg;
        cout<<avg;
    }
    cout<<pos;
}