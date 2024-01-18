#include<iostream>
using namespace std;

void main()
{
    int ir,kb, bit, t, tm, ts;
    cin>>ir>>kb;
    bit = kb*1024*8;
    t = bit/ir;
    tm = t/60; 
    ts = t%60;
    cout<<t<<endl<<tm<<":"<<ts;
}