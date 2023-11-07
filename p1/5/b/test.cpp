#include<iostream>
using namespace std;

int main()
{
    int n, prev, i, v, o;
    cin>>n;
    cin>>prev;
    for(i=1; i<=n; i++)
    {
        cin>>v;
        if(((v%100)-(prev%100)) != 1 )
        {
          o = 1;
        }
        prev = v;
    }
    if(o == 1)
    {
        cout<<"false";
    }
    else
    {
        cout<<"true";
    }
}