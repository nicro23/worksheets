#include<iostream>
using namespace std;

void main()
{
    char o;
    int cc, pn, fb;
    cin>>o>>cc>>pn;
    if(o =='c')
    {
        fb = 20;
    }
    else
    {
        fb = 10;
    }
    if(cc < 1100)
    {
        fb += 50;
    }
    else
    {
        if(cc>1100 && cc<1300)
        {
            fb += 70;
        }
        else
        {
            if( cc>1300 && cc<1500)
            {
                fb += 90;
            }
            else
            {
                fb+= 120;
            }
        }
    }
    fb+= pn;
    cout<<fb;
}