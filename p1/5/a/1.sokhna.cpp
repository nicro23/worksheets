#include<iostream>
using namespace std;

void main()
{
    int npriv, npikup, ntruck,nc, tc, inc, min, max, pin, pox;
    max = -99999;
    min = 999999;
    for(int i=1;i<=7;i++)
    {
        npriv = 0;
        npikup = 0;
        ntruck = 0;
        cin>>nc;
        for(int j=1; j<=nc;j++)
        {
            cin>>tc;
            if(tc == 1)
            {
                npriv++;
            }
            if(tc == 2)
            {
                npikup++;
            }
            if(tc == 3)
            {
                ntruck++;
            }
        }
        inc = npriv*5 + npikup*10 + ntruck*25;
        if(inc>max)
        {
            max = inc;
            pox = i;
        }
        if(ntruck<min)
        {
            min = ntruck;
            pin = i;

        }
    }
    cout<<"day with most income"<<pox<<endl;
    cout<<"day with lowest trucks"<<pin;
}