#include<iostream>
using namespace std;

void main()
{
    float tc, ac, rc, cl, fb;
    cin>>tc>>ac>>rc>>cl;
    if(tc == 1)
    {
        fb = 35000;
    }
    if(tc == 2)
    {
        fb = 38000;
    }
    if(tc == 3)
    {
        fb = 42000l;
    }
    if(ac == 1)
    {
        fb+= 850;
    }
    if(rc == 1)
    {
        fb+= 70;
    }
    if(cl == 1)
    {
        fb+= 250;
    }
    cout<<fb;
}