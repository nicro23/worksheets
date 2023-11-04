#include<iostream.h>
using namespace std;

void main()
{
    cin>>t1a>>t1b>>t1c>>t2a>>t2b>>t2c>>t3a>>t3b>>t3c;
    if(t1b == t3b)
    {
        if(t1c == t3c)
        {
            t1a+= t3a;
            cout<<t1a<<t1b<<t1c<<"+"<<t2a<<t2b<<t2c;
        }
    }
    if(t1b == t3b)
    {
        if(t1c == t3c)
        {
            t1a+= t3a;
            cout<<t1a<<t1b<<t1c<<t2a<<t2b<<t2c;
        }
    }
    if(t2b == t3b)
    {
        if(t2c == t3c)
        {
            t2a+= t3a;
            cout<<t1a<<t1b<<t1c<<"+"<<t2a<<t2b<<t2c;
        }
    }
}