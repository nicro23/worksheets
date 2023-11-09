#include<iostream>
using namespace std;

int main()
{
    int n, ct, j;
    long long r;
    cin>>n;
    for(int i =1; i<=n;i++)
    {
        cin>>r;
        ct = 0;
        for(j=1; j<=r;j++)
        {
            r = r - j;
            if(r<0)
            {
                break;
            }
            ct++;
        }
        cout<<ct;
    }
}