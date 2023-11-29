#include<iostream>
using namespace std;

void main()
{
    int nt, np, wp, wb, nb, ct, min, pos;
    float avg, tot;
    char tt;
    min = 99999;
    cin>>nt;
    for(int i= 1;i<=nt;i++)
    {
        ct = 0;
        tot = 0;
        cin>>tt>>np;
            if(tt =='b' && np< min)
            {
                min = np;
                pos = i;
            }

        for(int j=1;j<=np;j++)
        {
            cin>>wp>>wb>>nb;

        
            if(nb > 50)
            {
                ct++;
                tot += wb;
            }
        }
        avg = tot/ct;
        cout<<avg;
    }
}