#include<iostream>
using namespace std;

void read(int x[], int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
}
void fc(int x[], int y[],int n,int &pos1,int &pos2)
{
    int i , ct =0, k =0,j=n-1;
    for( i = 0;i<n;i++)
    {
        if(x[i] == i*2)
        {
            ct++;
            pos2 = i;
            y[i] = x[i];
            if(ct == 2)
            {
                break;
            }
            pos1 = i;
            y[i] = x[i];
        }
    }
    for(i =0 ;i<pos1;i++)
    {
        if(x[i] %2 != 0)
        {
            y[k++] = x[i];
        }
    }
    while(k<pos1)
    {
        y[k++] = -1;
    }
    for(i = pos1+1; i<pos2;i++)
    {
        y[i] = -1;
    }
    for(i = n-1;i>pos2;i--)
    {
        if(x[i]%2 != 0)
        {
            y[j--] = x[i];
        }
    }
    while(j>pos2)
    {
        y[j--] = -1;
    }
}

void avgbet(int x[],float &avg,int pos1,int pos2)
{
    int ct= 0;
    float tot = 0;
    for(int i=pos1;i<pos2;i++)
    {
        ct++;
        tot+= x[i];
    }
    avg = tot/ct;
}

void avgpos(int x[], int n, float &avg)
{
    int ct =0;
    float tot =0;
    for(int i =0;i<n;i++)
    {
        if(x[i]>0)
        {
            ct++;
            tot +=x[i];
        }
    }
    avg = tot/ct;
}

void add(int x[], int n,float a)
{
    for(int i = 0;i<n;i++)
    {
        x[i]+= a;
    }
}

void addneg(int x[], int n,float a)
{
    for(int i =0;i<n;i++)
    {
        if(x[i]<0)
        {
            x[i]+= a;
        }
    }
}

void main()
{
    int x[200],y[200],pos1,pos2,q[600],z[600],w[600];
    float a1,a2;
    read(x,200);
    fc(x,y,200,pos1,pos2);
    avgbet(x,a1,pos1,pos2);
    avgpos(y,200,a2);
    add(y,200,a1);
    add(y,200,a2);
    read(q,600);
    fc(q,z,600,pos1,pos2);
    add(z,600,a1);
    avgbet(q,a2,pos1,pos2);
    avgpos(z,600,a2);
    add(z,600,a1);
    add(z,600,a2);
    read(w,600);
    fc(w,q,600,pos1,pos2);
    avgbet(w,a2,pos1,pos2);
    avgpos(q,600,a2);
    addneg(q,600,a1);
    addneg(q,600,a2);
    read(y,200);
    fc(y,x,200,pos1,pos2);
    read(q,600);
    fc(q,w,600,pos1,pos2);
    read(x,200);
    fc(x,y,200,pos1,pos2);
    avgbet(x,a1,pos1,pos2);
    avgpos(y,200,a2);
    add(y,200,a1);
    add(y,200,a2);
}