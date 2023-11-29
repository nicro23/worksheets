#include<iostream>
using namespace std;

void main()
{
    int r, v, x, i, nv;
    r = 10;
    cin>>nv;
    for(i = 1; i<=nv; i++ , r*=10)
    {
        cin>>v;
        x = v%r;
        cout<<x;
    }
}