#include<iostream>
using namespace std;

void main()
{
    float tt, lc, ac, fb;
    cin>>tt>>lc>>ac;
    if(tt == 1)
    {
        fb = 17.5;
    }
    else 
    {
        if(tt == 2)
        {
            fb = 12;
        }
        else
        {
            fb = 8.75;
        }
    }
    if(lc == 1)
    {
        fb+= 4.5;
    }
    if(ac == 1)
    {
        fb+= 4.5;
    }
    cout<<fb;
}