#include<iostream>
#include<stdio.h>
using namespace std;

#include<iostream>
#include<stdio.h>
using namespace std;

void fun(char x[])
{
    //declare needed variables
    int i,size,j,k,wc;
    //count size of array
    for(i = 0;x[i] != '\0';i++)
    {

    }
    size = i;
    //loop from start to null searching for un
    for(i = 0;x[i] != '\0';i++)
    {
        if(x[i] == ' ')
        {
            if(x[i+1] == 'u' && x[i+2] == 'n')
            {
                i++;
                wc = 0;
                //count the word count of the word
                for(j=i;x[j] != ' ';j++)
                {
                    wc++;
                }
                //shift everything from the end word count + un + space
                for(k=size;k>j-1;k--)
                {
                    x[k+(wc/2)] = x[k];
                }
                //copy first half to emptied space
                k++;
                for(int l = 0;l<wc/2;l++)
                {
                    x[k++] = x[i++];
                } 
            }
        }
    }
}

int main()
{
char x[200];
gets_s(x);
fun(x);
cout<<x;
}

