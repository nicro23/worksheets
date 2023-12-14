#include<bits/stdc++.h>
using namespace std;
//b
int main()
{
    long long n, min = 999999999999999999, max = -999999999999999999;
    cin >> n;
    long long *x = new long long[n];
    for(int i= 0;i<n;i++)
    {
        cin>>x[i];
    }
    for(int i = 0;i<n-1;i++)
    {
        if(x[i]- x[i+1] > max)
        {
            max = x[i]- x[i+1];
        }
        if(abs(x[i]- x[i+1]) < min )
        {
            min = abs(x[i] - x[i+1]);
        }
    }
    cout<<max<<" "<<min;
}
