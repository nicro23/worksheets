#include<iostream>
using namespace std;

int main()
{
    int v, i, j, k, d1, d2, ct, ct2, n;
    n = 0;
    ct2 = 0;
    ct = 0;
    cin>>v;
    for(int i=2;i<v;i++)
    {
        if(v%i == 0)
        {
            ct++;
        }

    }
    for(int j=2;j<v;j++)
    {
        if( ct%2 != 0)
        {
        cout<<"rip"<<endl;
        break;
        }
        if(v%j == 0)
        {
            ct2++;
            if(ct2 == (ct/2))
            {
                d1 = j;
            }
            if(ct2 == (ct/2 + 1))
            {
                d2 = j;
            }
        }     
    }
    for(int k=2; k<(d1+d2);k++)
    {
        if((d1+d2)%k == 0)
        {
            n = 1;
        }
    }
    if(n == 1)
    {
        cout<<"no.";
    }
    else
    {
        cout<<"yes";
    }
}