#include<iostream>
using namespace std;

void main()
{
    float sb1, bb1, sb2, bb2, sb3, bb3, ps, pb, fb1, fb2, fb3;
    cin>>sb1>>bb1>>sb2>>bb2>>sb3>>bb3>>ps>>pb;
    fb1 = sb1*ps + bb1*pb;
    fb2 = sb2*ps + bb2*pb;
    fb3 = sb3*ps + bb3*pb;
    if(fb1>600)
    {
        fb1 *= 0.9;
    }
    if(fb2>600)
    {
        fb2 *= 0.9;
    }
    if(fb3>600)
    {
        fb3 *= 0.9;
    }
    cout<<fb1<<endl<<fb2<<endl<<fb3;
}