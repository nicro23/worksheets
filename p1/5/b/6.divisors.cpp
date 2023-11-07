#include<iostream>
using namespace std;

void main()
{
    int v, cte, cto, i;
    cin>>v;
    cto = 0;
    cte = 0;
    for(i=2;i<v;i++)
    {
        if(v%i ==0 && i%2 == 0)
        {
            cout<<i<<" ";
            cto++;
        }
        if(v%i ==0 && i%2 != 0)
        {
            cout<<i<<" ";
            cte++;
        }    
    }
    if(cto == 0 && cte >0)
    {
        cout<<"odds";
    }
    else
    {
        if(cte == 0 && cto>0)
        {
            cout<<"evens";
        }
        else
        {
            if( cte == 0 && cto == 0)
            {
                cout<<"prime number";
            }
            else
            {
            cout<<"mixed";
            }
        }
    }


}