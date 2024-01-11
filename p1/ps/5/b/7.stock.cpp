#include<iostream>
using namespace std;

void main()
{
    float prev_ss, i, cti, ctd;
    float ss, diff, toti, totd, avg_i, avg_d;
    toti = 0;
    totd = 0;
    cti = 0;
    ctd = 0;
    cin>>prev_ss;
    for(i=1;i<=11;i++)
    {
        cin>>ss;
        diff = ss-prev_ss;
        if(diff >0)
        {
            cti++;
            toti += diff;
        }
        if(diff <0)
        {
            ctd++;
            totd+= diff;
        }
        prev_ss= ss;
    }
    avg_i = toti/cti;
    avg_d = totd/ctd;
    cout<<cti<<endl<<ctd<<endl<<avg_i<<endl<<avg_d;
}