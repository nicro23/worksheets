#include<iostream>
using namespace std;

void fun(int x[],int n,int &ct,int &t)
{
    //prep&declare variables
    int pos1, pos2, pos3;
    ct=0;
    t=0;
    //loop from start to n 
    for(int i =0;i<n;i++)
    {
        //condition -num to count them
        if(x[i] < 0)
        {
            ct++;
            //condition ct reminder 3 3 times to catch pos
            if(ct%3 == 1)
            {
                pos1 = i;
            }
            if(ct%3 == 2)
            {
                pos2 = i;
            }
            if(ct%3 == 0)
            {
                pos3 = i;
            }
            //add tot of last 3 numbers
            if(ct>=3)
            {
                t = x[pos1] + x[pos2] + x[pos3];
            }
        }
    }
}

int main()
{
    int x[15] = {3,-10,15,16,23,-14,-11,65,82,-90,-18,35,-15,-21,33}, t, ct;
    fun(x,15,ct,t);
    cout<<ct<<endl<<t;
}
