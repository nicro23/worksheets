#include<iostream>
using namespace std;

void main()
{
    int x[30]={4,3,1,5,2,15,12,18,30,28,13,7,25,8,23,22,6,27,16,21,9,19,24,11,20,26,29,10,14,17}, ct=0,s,e,z1,ct2=0;
    while(ct < 30-1)
    {
        ct = 0;
        cin>>s>>e;
        z1 = x[e];
        for( ;s<e;e--)
        { 
            x[e] = x[e-1];
        }
        x[s] = z1;
        ct2++;
        for(int i =0;i<30;i++)
        {
            if(x[i]+1==x[i+1])
            {
                ct++;
            }
        }
    }
    cout<<ct2;
}