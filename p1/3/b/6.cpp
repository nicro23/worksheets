#include<iostream>
using namespace std;

void main()
{
    int hen1, hex1, men1, mex1, hen2, hex2, men2, mex2, hen3, hex3, men3, mex3, alh1, alt1, alh2, alt2, alh3, alt3, ct, p1, p2, p3, avg;
    cin>>hen1>>hex1>>men1>>mex1>>hen2>>hex2>>men2>>mex2>>hen3>>hex3>>men3>>mex3;
    ct = 0;
    alh1= hex1 - hen1;
    alt1 = (hex1*60 + mex1) - (hen1*60 + men1);
    if ( alt1 % 60 != 0)
    {
    alh1++;
    }
    if ( alt1/60 > 5)
    {
    ct++;
    }
    p2 = alh2*2;
    alh2= hex2 - hen2;
    alt2 = (hex2*60 + mex2) - (hen2*60 + men2);
    if ( alt2 % 60 != 0)
    {
    alh2++;
    }
    if ( alt2/60 > 5)
    {
    ct++;
    }
    p2 = alh2*2;
    alh3= hex3 - hen3;
    alt3 = (hex3*60 + mex3) - (hen3*60 + men3);
    if ( alt3 % 60 != 0)
    {
    alh3++;
    }
    if ( alt3/60 > 5)
    {
    ct++;
    }
    p3 = alh3*2;
    avg = (p1 + p2 + p3)/3;
    cout<<avg<<endl<<ct;

}