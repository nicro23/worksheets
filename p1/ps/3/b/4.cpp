#include<iostream>
using namespace std;

void main()
{
    int w1, a1, s1, o1, w2, a2, s2, o2, w3, a3, s3, o3, tot1, tot2, tot3, ct;
    cin>>w1>>a1>>s1>>o1>>w2>>a2>>s2>>o2>>w3>>a3>>s3>>o3;
    ct =0;
    tot1= 0;
    tot2 = 0;
    tot3 = 0;
    if ( a1 == 'y')
    {
    tot1 += 75;
    }
    if ( s1 == 'y')
    {
    tot1 += 45;
    }
    if ( o1 == 'y')
    {
    tot1 += 128;
    }
    if ( a2 == 'y')
    {
    tot2 += 75;
    }
    if ( s2 == 'y')
    {
    tot2 += 45;
    }
    if ( o2 == 'y')
    {
    tot2 += 128;
    }
    if ( 31 == 'y')
    {
    tot3 += 75;
    }
    if ( s3 == 'y')
    {
    tot3 += 45;
    }
    if ( o3 == 'y')
    {
    tot3 += 128;
    }
    if( tot1 > ( 9 * w1 * 24))
    {
    ct++;
    }
    if( tot2 > ( 9 * w2 * 24))
    {
    ct++;
    }
    if( tot3 > ( 9 * w3 * 24))
    {
    ct++;
    }
    cout<<ct<<tot1<<tot2<<tot3;
}