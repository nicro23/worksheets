#include<iostream>
using namespace std;
void main()
{
    int n, th, hun, hu, ten, te, u, num;
    cin>>n;
    if(n > 9999)
    {
     cout<<"entered number has 5 digits";
    }
    else
        {
        if(n>999)
            {
                th = n/1000;
                hun = n - (th*1000);
                hu = hun / 100;
                ten = hun - (hu*100);
                te = ten / 10;
                u = ten - (te*10);
                num= u*1000 + te*100 + hu*10 + th;
                cout<<num;
            }
    else
        {
        if(n>99)
            {
                hu = n /100;
                ten = n - (hu*100);
                te = ten / 10;
                u = ten - (te*10);
                num= u*100 + te*10 + hu;
                cout<<num;
            }
    else
        {
            if(n>9)
            {
                te = n/10;
                u = n - (te*10);
                num= u*10 + te;
                cout<<num;
            }
    else
        {
            cout<<n;
        }
        }
    
        }
        
        }
}


