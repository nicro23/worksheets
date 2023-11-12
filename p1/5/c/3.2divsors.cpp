#include<iostream>
using namespace std;

void main()
{
    int n1, n2, i, j, ct;
    cin>>n1>>n2;
    for(i=2;i<=(n1/2);i++)
    {
        if(n1%i == 0)
        {
            ct = 0;
            for(j=2;j<=(n2/2);j++)
            {
                if(n2%j==0)
                {
                    if((n1+n2)%2 == 0)
                    {
                        ct++;
                    }
                }
            }
            cout<<ct;
        }
    }
}