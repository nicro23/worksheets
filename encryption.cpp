#include<bits/stdc++.h>
using namespace std;

int main()
{
    char y[10],z[20];
    string x;
    cin>>x;
    for(int i =0;i<10;i++)
    {
        cin>>y[i];
    }
    //reverse
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    //substitution
    for(int i =0;i<10;i++)
    {
        x[i]+=5;
    }
    //expansion
    for(int i =0, k=0;i<10;i++)
    {
        y[k++] = x[i];
        x[i] = 0;
        y[k++] = k;
    }
    //unexpansion
    for(int i =0, k=0;i<10;i++)
    {
        x[i] = y[k++]
        k++;
    }
    //unsubstitution
    for(int i =0;i<10;i++)
    {
        x[i]-=5;
    }
    //unreverse
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    cout<<x;
}