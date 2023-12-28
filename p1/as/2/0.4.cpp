#include<iostream>
#include<stdio.h>
using namespace std;
void main()
{
    int pos;
    char x[200];
    gets_s(x);
    for(int i = 0;x[i]!='\0';i++)
    {
        if(x[i] == ' ')
        {
            if(x[i+1] == 'y' 
            && x[i+2] == 'e'
            && x[i+3] == 's')
            {
                pos = i+1;
            }
        }
    }
    cout<<pos;
}