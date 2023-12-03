#include<iostream>
using namespace std;

void main()
{
    int x[100],y[100];
    for(int i=0;i<100;i++)
    {
        cin>>x[i];
        cin>>y[i];
    }
    for(int i = 0;i<100;i++)
    {
        x[i] = x[i]*y[i];
        y[i] -= 1;
    }
    for(int i=0;i<100;i++)
    {
        cout<<x[i]<<endl;
        cout<<y[i]<<endl;
    }
    

}