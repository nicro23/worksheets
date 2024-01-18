#include<iostream>
using namespace std;

void main()
{
    float bw, bl, bh, pc, pf, w, pw, f;
    cin>>bw>>bl>>bh>>pc>>pf;
    w = bh*bw*2 + bh*bl*2 + bh*bw;
    pw = w*pc;
    f = bw*bl*pf;
    cout<<pw<<endl<<f;
}