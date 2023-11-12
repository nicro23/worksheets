#include<iostream>
using namespace std;

void main()
{
    int rt, nc, t, isp, ism ,isv, p;
    cin>>rt>>nc>>t>>isp>>ism>>isv;
    if (rt=='a')
    {
    p = nc*20;
    }
    if (rt=='b')
    {
    p = nc*12;
    }
    if (rt=='c')
    {
    p = nc*18;
    }
    if (rt=='d')
    {
    p = nc*142;
    }
    if (isp=='y')
    {
    p += t*10;
    }
    if (ism=='y')
    {
    p += 30;
    }
    if (isv=='y')
    {
    p += t*25;
    }
    cout<<p;

}