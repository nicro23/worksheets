#include<iostream>
using namespace std;

void main()
{
    int v1, v2, diff, diff_prev, f;
    char n;
    f = 0;
    for(int i=1; ;i++)
    {   
        cout<<"y or n?";
        cin>>n;
        if(n == 'n')
        {
            break;
        }
        if(i>1)
        {
            v2 = v1;
        }
        cin>>v1;
        if(i>1)
        {
            diff = v1 - v2;
            if(diff_prev != diff && i>2)
            {
                f = 1;
            }
            for(int j=1;j<=diff;j++)
            {
                cout<<"y or n?";
                cin>>n;
                if(n == 'n')
                {
                break;
                }
                
                if(j>1)
                {
                    v2 = v1;
                    if( v2 != v1)
                    {
                        f = 1;
                    }
                }
                cin>>v1;
            }
            diff_prev = diff;
        }
        if( n == 'n')
        {
            break;
        }       
    }
    if (f == 1)
    {
        cout<<"false";
    }
    else
    {
        cout<<"true";
    }   
}