#include<iostream>
using namespace std;

void main()
{
    float ad1, ad2, vad1, vad2, inc1, inc2, inc;
    cin>>ad1>>ad2>>vad1>>vad2;
    if(vad1 > (ad1*0.5))
    {
        inc1 = vad1*0.03;
    }
    if(vad2 > (ad2*0.5))
    {
        inc2 = vad2*0.03;
    }
    inc = inc1 + inc2;
    cout<<inc;
}