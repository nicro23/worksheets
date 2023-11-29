#include<iostream>
using namespace std;

void main()
{
    int ht, nl, nt, pm, min, ct, pos;
    float avg, tot;
    char cd;
    min = 99999;
    ct = 0;
    tot = 0;
    cin>>nt;
    for(int i =1;i<=nt;i++)
    {
        cin>>ht>>nl;
        for(int j=1;j<=nl;j++)
        {
            cin>>cd>>pm;
            if(cd == 'a')
            {
                ct++;
                tot += pm;
            }
        }
        if(ht<min)
        {
            min = ht; //nl;
            pos = nl;
        }
    }
    avg = tot/ct;
    cout<<min<<avg;
}