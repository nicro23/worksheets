#include<iostream>
#include<stdio.h>
using namespace std;
void main()
{
    int i , k, z;
    char x[200];
    gets_s(x);
    for(i = 0;x[i]!='\0';i++)
    {

    }
    i--;
    for(k = 0;k<i;k++,i--)
    {
        z = x[k];
        x[k] = x[i];
        x[i] = z;
    }
}