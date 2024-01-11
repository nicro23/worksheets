#include<iostream>
using namespace std;

int main()
{
    int nn;
    float n;
    int tot = 0;
    cin>>nn;
    for(int i=1;i<=nn;i++)
    {
        cin>>n;
        int v = n;
        float x = n - v;
        tot+= x*100 + 0.5;
    }
    cout<<tot;
}