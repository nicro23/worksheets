#include<iostream>
#include<stdio.h>
using namespace std;
void main()
{
    int i1,i2,i,ct=0,pos1,pos2,ct2=0;
    char x[200],y[200],z;
    gets_s(x);
    gets_s(y);
    cin>>i1>>i2;
    for( i =0;x[i]!='\0';i++)
    {
        if(x[i]== ' ')
        {
            ct++;
            if(ct == (i1 - 1))
        {
            pos1 = i+1;
        }
        }
        
    }
    ct = 0;
    for( i =0;y[i]!='\0';i++)
    {

        if(y[i]== ' ')
        {
            ct++;
            if(ct == (i2 - 1))
            {
                pos2 = i+1;
            }
        }
    }
    for(i = 0 ; ct2 < 2 ;i++, pos1++, pos2++)
    {
        if(x[i] == '\0' || y[i] == '\0')
        {
            ct2++;
        }
        z = x[pos1];
        x[pos1] = y[pos2];
        y[pos2] =  z;
    }
    cout<<x<<endl<<y;
     

}