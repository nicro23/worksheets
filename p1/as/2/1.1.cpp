#include<iostream>
#include<stdio.h>
using namespace std;
void main()
{
    char x[400], char t;
    gets_s(x);
    for(int i= 0;x[i]!='\0';i++)
    {
        if(x[i] == '.')
        {
            if(x[i+1] == 'c'
            && x[i+2] == 'o'
            && x[i+3] == 'm')
            {
                t = 'c';
            }
            if(x[i+1] == 'o'
            && x[i+2] == 'r'
            && x[i+3] == 'g')
            {
                t = 'o';
            }
            if(x[i+1] == 'e'
            && x[i+2] == 'd'
            && x[i+3] == 'u')
            {
                t = 'e';
            }
        }
    }
    if( t == 'c')
    {
        cout<<"company";
    }
    if( t == 'o')
    {
        cout<<"organization";
    }
    if(t == 'e')
    {
        cout<<"education";
    }
}
