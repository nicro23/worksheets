#include<iostream>
using namespace std;

int main()
{
    int t,l,w,h;
    cin>>t;
    for(int i =1;i<=t;i++)
    {
        cin>>l>>w>>h;
        if(l < 21 && w <21 && h<21 && l*w*h <= 20*20*20)
        {
            printf("Case %i: good\n", i);
        }
        else
        {
            printf("Case %i: bad\n", i);
        }
    }
}