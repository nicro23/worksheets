#include<iostream.h>
using namespace std;

void main()
{
    if(n > 9999 || n<999)
    {
        cout<<"error";
    }
    else
    {
        if( n>999)
        {
        th = n/1000;
        hu = (n - (th*1000)) / 100;
        te = (n - ((th*1000) + (hu*100))) / 10;
        u = n - ((th*1000) + (hu*100) + (te*10));
        l = th +hu
        m = hu + te
        n = te + u
        
        if (l > 9 && m > 9 && n > 9)
            {
                num = l*10000
            }
        cout<<l<<m<<n;
        }
    }
    else
    {
    if(n>99)
    {
    hu = (n /100);
    te = n - ( (hu*100) / 10);
    u = n -  ((hu*100) + (te*10));
    l =  hu + te;
    m = te + u;
    cout<<l<<m;
    }
    }
    else
    {
    if(n>9)
    {
    te = n/10;
    u = n - (te*10)
    l = hu+te;
    cout<< l;
    }
    }
    else
    {
    cout<<n;
    }


}