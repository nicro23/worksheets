#include<iostream>
using namespace std;

void main()
{
    int s1, p1, d1 , s2, p2, d2, s3, p3, d3, b1, b2, b3, fb1, fb2, fb3, ct, min;
    cin>>s1>>p1>>d1>>s2>>p2>>d2>>s3>>p3>>d3;
    b1 = s1*3.95;
    b2 = s2*3.95;
    b3 = s3*3.95;
    fb1 = b1;
    fb2 = b2;
    fb3 = b3;
    ct= 0;
    min = 99999;
    if ( p1 == 1)
    {
    fb1+= b1*0.5;
    ct++;
    }
    if ( p2 == 1)
    {
    fb2+= b2*0.5;
    ct++;
    }
    if ( p3 == 1)
    {
    fb3+= b3*0.5;
    ct++;
    }
    if ( d1 == 'f')
    {
    fb1+= b1*0.4;
    }
    if ( d2 == 'f')
    {
    fb2+= b2*0.4;
    }
    if ( d3 == 'f')
    {
    fb3+= b3*0.4;
    }
    if ( fb1 < min)
    {
    min = fb1;
    }
    if ( fb2 < min)
    {
    min = fb2;
    }
    if ( fb3 < min)
    {
    min = fb3;
    }
    cout<<ct<<endl<<min;
}