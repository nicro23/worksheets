#include<iostream>
using namespace std;

void main()
{
    int n1, n2, n3, nt, ct;
    cin>>n1>>n2>>n3;
    //sort numbers
    if (n3<n1)
        {
            nt = n1;
            n1 = n3;
            n3 = nt;
        }
    if(n3<n2)
    {
        nt = n2;
        n2 = n3;
        n3 = nt;
    }
    if(n2<n1)
    {
        nt = n1;
        n1 = n2;
        n2 = nt;
    }
    //count divisablity
    ct = 0;
    if ( n2%n1 == 0)
    {
        ct++;
    }
    if ( n3%n1 ==0)
    {
        ct++;
    }
    if ( n3%n2 ==0)
    {
        ct++;
    }
    cout<<n1<<","<<n2<<","<<n3<<endl<<ct;

}