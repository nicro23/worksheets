#include<iostream>
using namespace std;

int main()
{
    int t, a,b,c;
    cin>>t;
    for(int i = 1;i<=t;i++)
    {
        cin>>a>>b>>c;
        if(a+b>=10 || a+c >=10 || b+c >= 10)
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
}