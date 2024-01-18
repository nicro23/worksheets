#include<iostream>
using namespace std;

void main()
{
    int ps, pl, pc, pb, fp;
    char ts, tc;
    cin>>ts>>tc>>ps>>pl>>pc>>pb;
    if(ts == 's')
    {
        fp = ps;
    }
    else
    {
        fp = pl;
    }
    if(tc == 'c')
    {
        fp+= pc;
    }
    else 
    {
        fp+= pb;
    }
    cout<<fp;
}