#include<iostream>
using namespace std;

void main()
{
    cin>>n;
    tot = 0;
    ct = 0;
    max = -99999;
    for(i=1;i<=n;i++)
    {
        cin>>lb>>nd;
        cst = 0;
        if(lb>200)
        {
            tot += nd;
            ct++;
        }
        for(j=1;j<=nd;j++)
        {
            cin>>prc_dec>>prc_chrg;
            if(i > (n-10))
            {
                cst += prc_dec + prc_chrg;
            }
        }
        if(cst > max)
        {
            max = cst;
            pos = i;
        }
    }
    avg = tot/ct;
    cout<<avg<<pos;
}