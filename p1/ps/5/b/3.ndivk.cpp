#include<iostream>
using namespace std;

void main()
{
    float n, tot, ct, avg, i, l;
    int v, k;
    tot = 0;
    ct = 0;
    cin>>n>>k;
    for(i = 1;i<=n;i++)
    {
        cin>>v;
        l = v;
        if((v%k) == 0)
        {
            tot+= l;
            ct++;
        }
    }
    avg = tot/ct;
    cout<<avg;
}