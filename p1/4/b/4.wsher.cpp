#include<iostream>
using namespace std;

void main()
{
    float n, ncw, ni, eb, tot, cta, min , pos, avg;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>ncw>>ni>>eb;
        if(ncw == 1 && ni == 1)
        {
            tot+= eb;
            cta++;
        }
        if(eb<min)
        {
            min = eb;
            pos = i;
        }
    }
    avg =tot/cta;
    cout<<avg<<endl<<pos;
}