#include<iostream>
#include<stdio.h>
using namespace std;

void morefun(char x[])
{
    int i,k,ct =0,l,pos;
  for(i = 0;x[i]!='\0';i++)
  {

  }
  x[i++] = ' ';   
  for(k = i-1;x[k]>0-1;k--)
  {
    ct++;
    if(x[k]== ' ' || k == 0)
    {
        if(k == 0)
        {
          ct++;
          k--;
        }
        l = ct - 1;
        pos = k+2;
        if(l == 2)
        {
            x[i++] = x[pos--];
            x[i++] = x[pos];
            x[i++] = ' ';
        }
        ct = 0;
    }
  }
  x[i] = '\0';
}

int main()
{
    char x[200];
    gets_s(x);
    morefun(x);
    cout<<x;
}