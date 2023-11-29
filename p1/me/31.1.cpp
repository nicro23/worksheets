#include<iostream>
using namespace std;

void main()
{
    int nc, tc, d, wt, prc, max, pos, posd, tot, ctm, ctk;
    char tc;
    max =-999999;
    for(int i = 1;i<=30;i++)
    {
        cin>>nc;
        ctm =0;
        ctk =0;
        tot =0;
        for(int j = 1;j<=nc;j++)
        {
            cin>>tc>>d>>wt>>prc;
            if((d+wt) > max)
            {
                max = (d+wt);
                pos = j;
            }
            if(tc == 'm')
            {
                ctm++;
            }
            if(tc == 'k')
            {
                ctk++;
            }
            tot+= prc;
        }
        if(ctk>ctm)
            {
               cout<<tot<<endl; 
            }
    }
    cout<<pos;
}