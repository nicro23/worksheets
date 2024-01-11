#include<iostream>
using namespace std;

void fun(int x[], int y[], int n, int &r, int &l)
{
    int i,e,s;
    l = 0;
    r = 0;
    //s1 find the seperator
    //s1.1 loop to count odds
    for(i = 0;i<n-2 ;i++)
    {
        if(
            x[i]%2 !=0 &&
            x[i+1]%2 !=0 &&
            x[i+2]%2 !=0 )
            {
                break;
            }
    }
    //s1.2 catch the i and i+2
    e = i;
    s = i+3;
    //s2 loop to count zeros from 0 to i
    for( i = 0;i<e;i++)
    {
        if(y[i]==0)
        {
            l++;
        }
    }
    //s3 loop to count zeros from i+2 to n
    for( i = s;i<n;i++)
    {
        if(y[i] == 0)
        {
            r++;
        }
    }
}

int main()
{
    int x[15] = {3,10,15,16,23,14,11,65,82,33,21,35,28,30,33};
    int y[15] = {6,0,0,20,0,11,0,9,0,20,30,0,7,0,0};
    int n = 15, r=0,l=0;
    fun(x,y,n,r,l);
    cout<<l<<endl<<r;
}
