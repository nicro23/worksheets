#include<iostream>
using namespace std;

void main()
{
float w1, h1, w2, h2, w3, h3, min, ct, ctavg, tot, avg;
cin>>w1>>h1>>w2>>h2>>w3>>h3;
min = 9999;
ct = 0;
if ( w1 < min )
{
min = w1;
}
if ( w1 <=( h1 - 110))
{
 ct++;
}
else
{
tot+=w1;
ctavg++;
}
if ( w2 < min )
{
min = w2;
}
if ( w2 <=( h2 - 110))
{
 ct++;
}
else
{
tot+= w2;
ctavg++;
}
if ( w3 < min )
{
min = w3;
}
if ( w3 <=( h3 - 110))
{
 ct++;
}
else
{
tot+= w3;
ctavg++;

avg = tot/ctavg;
cout<<min<<ct<<avg;
}