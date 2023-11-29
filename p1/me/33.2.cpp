#include<iostream>
using namespace std;

int main()
{
    int j, v, f, ct, nr, l, nl;
    ct = 0;
    f = 0;
    l = 1;
    j = 10;
    cin>>v;
    for(int i = 1; ;i*=10)
    {
        if(v/i == 0)
        {
            break;
        }
        ct++;
    }
    for(int k = 1;k<=ct;k++)
    {
        l *= 10;
    }
    for(int x = 1 ; x<=(ct/2); j*=10 , l=l/10, x++)
    {
        nr = (v%j)/(j/10);
        if((nr%2) == 0)
        {
            f = 1;
        }
        nl = (v%l)/(l/10);
        if((nl%2) != 0)
        {
            f = 1;
        }
    }
    if( f == 1)
    {
        cout<<"FALSE";
    }
    else
    {
        cout<<"true.";
    }
}