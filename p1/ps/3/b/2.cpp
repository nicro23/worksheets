#include<iostream>
using namespace std;

void main()
{
    int v1, v2, v3, n1, n2, ctn, totn, ctm, totm, diff, avgm, avgn, n, m;
    cin>>v1>>v2>>v3>>n1>>n2;
    if(!v1%n)
    {
    ctn++;
    totn+= v1;
    }
    if(!v1%m)
    {
    ctm++;
    totm+= v1;
    }
    if(!v2%n)
    {
    ctn++;
    totn+= v2;
    }
    if(!v2%m)
    {
    ctm++;
    totm+= v2;
    }
    if(!v3%n)
    {
    ctn++;
    totn+= v3;
    }
    if(!v3%m)
    {
    ctm++;
    totm+= v3;
    }
    avgn = totn/ctn;
    avgm = totm/ctm;
    if(avgn>avgm)
    {
    diff= avgn - avgm;
    }
    else
    {
    diff = avgm - avgn;
    }
    cout<<diff; 
}