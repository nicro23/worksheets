#include<iostream>
using namespace std;

void read(int x[],int n)
{
    for(int i =0;i<n;i++)
    {
        cin>>x[i];
    }
}
void gc(int  x[], int y[], int n)
{
    int k =0,totr=0,totl=0,i,m =(n/2);
    for(i =m-1;x[i]!= -1 && i>-1;i--)
    {
        totl += x[i];
    }
    for(i =m;x[i]!= -1 && i<n;i++)
    {
        totr += x[i];
    }
    if(totr>totl)
    {
        for(i =m;i<n;i++)
        {
            if(x[i]%2 == 0)
            {
                y[k++] = x[i];
            }
        }
    }
    else
    {
        for(i =0;i<m;i++)
        {
            if(x[i]%2 == 0)
            {
                y[k++] = x[i];
            }
        }
    }
    while(k<n)
    {
        y[k++] = -1;
    }
}
void mny1(int x[], int n, int &a)
{
    a = 0;
    for( int i = 0;i<(n/2);i++)
    {
        if(x[i]== -1)
        {
            a++;
        }
    }
}
void swphlf(int x[], int n)
{
    int z,i =0,k;
    for(k=n/2;k<n;k++)
    {
        z = x[i];
        x[i] = x[n];
        x[n] = z;
        i++;
    }
}
void add2hlf(int x[], int n, int a)
{
    for(int i = n/2;i<n;i++)
    {
        if(x[i]!= -1)
        {
            x[i] += a;
        }
    }
}
void add(int x[], int n, int a)
{
    for(int i =0;i<n;i++)
    {
        x[i]+= a;
    }
}
void main()
{
    int x[200],y[200],a1,a2,q[600],z[600],w[600];
    read(x,200);
    gc(x,y,200);
    mny1(y,200,a1);
    swphlf(x,200);
    add2hlf(x,200,a1);
    add(y,200,a1);
    mny1(y,200,a2);
    swphlf(x,200);
    add2hlf(x,200,a2);
    gc(x,y,200);
    read(q,600);
    gc(q,z,600);
    swphlf(q,600);
    mny1(z,600,a1);
    gc(q,w,600);
    read(q,600);
    gc(q,w,600);
    mny1(w,600,a1);
    swphlf(q,600);
    add2hlf(q,600,a1);
    add(w,600,a1);
    read(x,200);
    gc(x,y,200);
    read(q,600);
    gc(q,z,600);
}