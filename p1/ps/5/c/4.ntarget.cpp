#include<iostream>
using namespace std;

void main()
{
    cin>>n>>t;
    for(i=1;i<n;i++)
    {
        x=i;
        tot= 0;
        while(x!=n)
        {
            t+= x++;
        }
        x=n;
        while(x!=i)
        {
            tot+= x-2;
            x = n-2
        }
        if(tot==t)
        {
            cout<<i;
            break;
        }
    }
}