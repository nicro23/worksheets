#include<iostream>
using namespace std;

void main()
{
    int fc, sc, c, l, s;
    cin>>fc>>sc>>c;
    for(l=1;l<=10;l++)
    {
        for(s=1;s<=l;s++)
        {
            if( (fc*l-sc*s) == c )
            {
                cout<<l<<" "<<s<<endl;
            }
        }
    }
}