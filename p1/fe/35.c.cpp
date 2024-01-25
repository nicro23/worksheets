#include<iostream>
#include<stdio.h>
using namespace std;

void fun(char x[], int n)
{
    //prep var
    int i, j, k, ctl = 0, cts = 0, pos, pos1, pos_cp, ws, is=0;
    //loop from start to n to count n wrd size
    for (i = 0; x[i] != '\0'; i++)
    {
        ctl++;
        if (x[i] == ' ')
        {
            cts++;
            if (cts == n)
            {
                ws = ctl-1;
                pos = i - ws;
                break;
            }
            ctl = 0;
        }
    }
    //loop from start to end
    for (i = 0; x[i] != '\0'; i++)
    {
        ctl++;
        if (x[i] == ' ')
        {
            //condition same word count
            if (ctl == ws+1)
            {
                //loop from wrd count+1 for word count times
                pos_cp = pos;
                j = i - (ws / 2);
                for (k = 0; k < ws / 2; k++)
                {
                    if (x[j++] != x[pos_cp++])
                    {
                        is = 1;
                    }
                }
                //check middle char
                j = i - (ws / 2) - 1;
                if (x[j] != x[pos_cp++])
                {
                    is = 1;
                }
                //loop from after space for word count times +1
                j = i - ws;
                for (k = 0;k < (ws / 2); k++)
                {
                    if (x[j++] != x[pos_cp++])
                    {
                        is = 1;
                    }
                }
                //condition flag
                if (is == 0)
                {
                    //shift to erase
                    for (j = i + 1; x[j] != '\0'; j++)
                    {
                        x[j - ws - 1] = x[j];
                    }
                    x[j - ws - 1] = '\0';
                }
                is = 0;
            }
            ctl = 0;
        }
    }
}

void main()
{
    char x[200];
    gets_s(x);
    fun(x, 3);
    cout << x;
}