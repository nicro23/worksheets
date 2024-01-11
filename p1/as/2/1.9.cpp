#include<iostream>
#include<stdio.h>
using namespace std;

void main()
{
    int ct=0, l, i, ly, pos,cpos,n,ct2,k;
    char x[200], y[200];
    gets_s(x);
    cin>>y;
    for(ly =0;y[i]!='\0';i++)
    {
    }
    for(i=0;x[i]!='/0';i++)
    {
        ct++;
        if( x[i] == ' ')
        {
            l = ct-1;
            ct2 = i + 1;
            pos = i - l;
            cpos = pos;
            if(  l == ly)
            {
                n = 0;
                for ( k=0;k<ly;k++)
                {
                    if( x[cpos++] != y[k])
                    {
                        n = 1;
                        break;
                    }
                }
                if(n == 0)
                {
                    for( k =pos;x[ct2] != '\0';k++)
                    {
                        x[k] = x[ct2++];
                    }
                    x[k] = '\0';
                    i = pos;
                }
            }
            ct = 0;
        }
    }
}