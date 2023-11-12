#include<iostream>
using namespace std;

void main()
{
    int val, num, i, a, k, b, l, j;
    cin>>val>>num;
    for(i=1;i<=10;i++)
    {
        a = 1;
        for(k=0; k<num;k++)
        {
            a*= i;
        }
        for(j=1;j<=10;j++)
        {
            b = 1;
            for(l=0;l<num;l++)
            {
                b*= j;
            }
            if( a + b == val)
            {
                break;
            }
        }
        if( a + b == val)
            {
                cout<<i<<" "<<j;
                break;
            }
    }
}