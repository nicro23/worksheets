#include<iostream>
#include<stdio.h>
using namespace std;
void main()
{
    int i , k;
    char x[200],y[200];
    gets_s(x);
    gets_s(y);
    for(i = 0;x[i]!='\0';i++)
    {

    }
    x[i++] = ' ';
    for(k = 0;y[k] !='\0';k++)
    {
        x[i++] = y[k];
    }
    x[i] = '\0';
}