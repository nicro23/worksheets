#include<iostream>
using namespace std;

void main()
{
    int fp1, ftc1, fd1, fp2, ftc2, fd2, fp3, ftc3, fd3, min, ct;
    cin>>fp1>>ftc1>>fd1>>fp2>>ftc2>>fd2>>fp3>>ftc3>>fd3;
    ct = 0;
    min = 9999;
    if(fd1==3)
    {
    if( fd1< min)
    {
    min = fd1;
    }
    }
    if(fd2==3)
    {
    if( fd2< min)
    {
    min = fd2;
    }
    }
    if(fd3==3)
    {
    if( fd3< min)
    {
    min = fd3;
    }
    }
    if(!ftc1)
    {
    ct++;
    }
    if(!ftc2)
    {
    ct++;
    }
    if(!ftc3)
    {
    ct++;
    }
    cout<<min<<ct;
}