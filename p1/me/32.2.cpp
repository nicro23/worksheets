#include <iostream>
using namespace std;

void main()
{
    int v, ct, pv, r, x, l, m, nv, c;
    ct = 0;
    pv = 10;
    cin>>v;
    nv = v;
    for(int i = 1; ;i*=10)
    {
        if(v/i == 0)
        {
            break;
        }
        ct++;
    }
    
    for(int j =1; j<ct;j++ , pv*=10)
    {

        r = nv%(pv/10);
        if(j==1)
        {
            c = nv%10;
        }
        l = nv/(pv*10);
        m = nv%(pv*10) /pv;
        x = l*(pv*10) + c*pv + m*(pv/10) + r;
        nv = x;
        cout<<x<<endl;
    }

}
