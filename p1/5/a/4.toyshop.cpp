#include<iostream>
using namespace std;

void main()
{
    int pa, pb, pc, c, na, nb, nc, pos, bill, isofr;
    int ct = 0;
    int inc = 0;
    int max = -99999;
    for(int i = 1; i<=30; i++)
    {
        cin>>pa>>pb>>pc>>isofr>>c;
         if(isofr ==1)
            {
                ct++;
            }
        for(int j=1; j<= c;j++)
        {
            cin>>na>>nb>>nc;
            while(isofr == 1 && na > 1 && nb > 1 && nc > 1 )
            {
                nc--;
                
            }
            bill = pa*na + pb*nb + pc*nc;
            cout<<bill<<endl;
            inc+= bill;
        }
        if(inc>max)
        {
            max = inc;
            pos = i;
        }

    }
    cout<<ct<<max;
}