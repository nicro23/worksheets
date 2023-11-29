#include<iostream>
using namespace std;

void main()
{
    int k, n, i, v, j, lm1, rm1, rm2, lm2, v1, f;
    cin>>n;
    for(i =1;i<=n;i++)
    {
        cin>>v;
        if(i==1)
        {
            for(j=1; ;j*=10)
            {
                if(v/j ==0)
                {
                    break;
                }
            }
            lm1 = v/(j/10);
        }    
        if(i == 2)
        {
            rm1 = v%10;
        }
        if(i>1)
        {
            rm2 = v1%10;
        }
            v = v1;
            for(k = 1; ;k*=10)
            {
                if(v/k == 0)
                {
                    break;
                }
            }
            lm2 = v/(k/10);
        
    }
    f = lm2*1000 + rm2*100 + rm1*10 + lm1;
    cout<<f;
}