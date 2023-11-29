#include<iostream>
using namespace std;

void main()
{
    int n, v, rm, lm, fls, j;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v;
        if(i%2 != 0)
        {
            rm = v%10;
        }
        if(i%2 == 0)
        {
            for(j = 1; ;j*=10)
            {
                if(v/j == 0)
                    {
                    break;
                }
            }
            lm = v/(j/10);
        }
        if(i>1)
        {
            if(rm != lm)
            {
                fls = 1;
            }
        }
    }
    if(fls == 1)
    {
        cout<<"false";
    }
    else
    {
        cout<<"true";
    }   
}