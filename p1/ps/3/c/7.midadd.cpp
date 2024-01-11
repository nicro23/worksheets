#include<iostream>
using namespace std;

void main()
{
    int n, te, u, sum, sumte, nn;
    cin>>n;
    if(n>9 && n<100)
    {
        te = n/10;
        u = n%10;
        sum = te + u;
        if(sum > 9)
        {
            sumte = sum/10;
            nn = (te + sumte)*100 + (sum%10)*10 + u;
        }
        else
        {
            nn = te*100 + sum*10 + u;
        }
    cout<<sum<<endl<<nn;
    }
    else
    {
        cout<<"error";
    }
}