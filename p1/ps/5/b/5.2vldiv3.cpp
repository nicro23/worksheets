#include<iostream>
using namespace std;

void main()
{
    int n1,n2,nt;
    cin>>n1>>n2;
    if(n2<n1)
    {
        nt = n1;
        n1 = n2;
        n2 = nt;
    }
    while(n1 != n2)
    {
        if((++n1%3) == 0)
        {
            cout<<n1<<endl;
        }
    }
}