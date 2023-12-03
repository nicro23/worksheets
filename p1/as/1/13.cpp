#include<iostream>
using namespace std;

void main()
{
    int x[8],a, o = 128;
    cin>>a;
    for(int i=0;i<8;i++)
    {
        if(a>=o)
        {
            x[i] = 1;
            a -= o;
        } 
        else
        {
            x[i] = 0;
        }
        o /= 2;
    }
    for(int i = 0;i<8;i++)
    {
        cout<<x[i];
    }
}