#include<iostream>
using namespace std;

void main()
{
    int i,x[40],wid, tot =0,rem;
    for(i =0;i<40;i++)
    {
        if(i%2==0)
        {
            cin>>x[i];
            tot += x[i];
        }
        else
        {
            x[i] = 1;
        }
    }
    tot = (90 - tot);
    rem = tot%20;
    wid = (tot/20);
    if( rem == 0)
    {
        for(i = 1;i<40;i+=2)
        {
            x[i] = wid;
        }
    }
    else
    {
        for(i =1;rem>0;i+=2, rem--)
        {
            x[i] = wid + 1;
        }
        while(i<40)
        {
            x[i] = wid;
            i+=2;
        }
    }
    for(i=0;i<40;i++)
    {
        cout<<x[i]<<" ";
    }

}