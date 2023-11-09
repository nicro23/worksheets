#include<iostream>
using namespace std;

void main()
{
    int val, num, i, a, k, b, l, j;
    cin>>val>>num;
    for(i=1;i<=10;i++)
    {
        a = i;
        for(k=1; k<num;k++)
        {
            a*= i;
        }
        for(j=1;j<=10;j++)
        {
            b = j;
            for(l=1;l<num;l++)
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