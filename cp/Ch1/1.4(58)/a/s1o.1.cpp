#include<iostream>
using namespace std;

int main()
{
    int t,ct,a,b,c;
    cin>>t;
    for(int i = 1;i<=t;i++)
    {
        ct =0;
        cin>>a>>b>>c;
        if(a+b>=10)
        {
            ct=1;
        }
        if(a+c>=10)
        {
            ct=1;
        }
        if(b+c >=10)
        {
            ct=1;
        }
        if(ct==1)
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
}