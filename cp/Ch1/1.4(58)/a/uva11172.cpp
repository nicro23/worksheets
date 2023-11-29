#include<iostream>
using namespace std;

int main()
{
    int t,a,b;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        if(a-b > 0)
        {
            cout<<">"<<endl;
        }
        if(a-b == 0)
        {
            cout<<"="<<endl;
        }
        if(b-a > 0)
        {
            cout<<"<"<<endl;
        }
    }
}