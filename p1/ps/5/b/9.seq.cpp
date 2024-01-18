#include<iostream>
using namespace std;

void main()
{
    int nn, x, y;
    cin>>x>>nn;
    cout<<x<<endl;
    for(int i=1;i<nn;i++)
    {
        y = 3*x +26;
        x=y;
        cout<<y<<endl;
    }
}