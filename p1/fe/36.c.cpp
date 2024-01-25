#include<iostream>
#include<stdio.h>
using namespace std;

void fun(char x[], char y[])
{
    //prep var
    int i, j = 0;
    //loop from start to finish
    for (i = 0; x[i] != '\0'; i++)
    {
        //condition dbl letter
        if (x[i] == ' ' && x[i + 1] == x[i + 2])
        {
            //cpy word to y
            while (x[++i] != ' ')
            {
                y[j++] = x[i];
            }
            i--;
            y[j++] = ' ';
        }
    }
    y[j] = '\0';
}

void main()
{
    char x[200], y[200];
    gets_s(x);
    fun(x, y);
    cout << y;
}