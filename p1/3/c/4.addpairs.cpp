#include<iostream>
using namespace std;

void main()
{
    int n, th, hu, te, u, l, m, num;
    cin>>n;
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
        l = th + hu;
        m = hu + te;
        n = te + u;
        
        if(n>9)
            {
                if(m>9)
                {
                    num = l*10000 + m*100 + n;
                }
                else
                {
                    num = l*1000 + m*100 + n;
                } 
            }
        else
            {
                if(m>9)
                {
                    num = l*1000 + m*10 + n;
                }
                else
                {
                    num = l*100 + m*10 + n;
                } 
            }
        
        }
        cout<<num;
    }
} 
    //else
    //{
    //if(n>99)
    //{
    //hu = (n /100);
    //te = n - ( (hu*100) / 10);
    //u = n -  ((hu*100) + (te*10));
    //l =  hu + te;
    //m = te + u;
    //cout<<l<<m;
    //}
    //}
    //else
    //{
    //if(n>9)
    //{
    //te = n/10;
    //u = n - (te*10)
    //l = hu+te;
    //cout<< l;
    //}
    //}
    //else
    //{
    //cout<<n;
    //}