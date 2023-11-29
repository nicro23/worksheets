#include<iostream>
using namespace std;

void main()
{
    int ctd, d, ct, i, np, nc1, nc2, ns, ct, inc, max, pos;
    char isr;
    ctd = 0;
    max = -99999;
    for(d = 1;d<=365;d++)
    {
        ct = 0;
        for(i=1;i<=20;i++)
        {
            cin>>isr;
            if(isr == 'y')
            {
                cin>>np>>nc1>>nc2>>ns;
                if(d == 210)
                {
                    inc = np*100 + nc1*30 + nc2*35 + ns*85;
                    if(inc > max)
                    {
                        max = inc;
                        pos = np;
                    }
                }
            }
            if(isr == 'n')
            {
                ct++;
            }
            
        }
        if(ct == 20)
        {
            ctd++;
        }
    }
    cout<<np<<endl<<ctd;
}