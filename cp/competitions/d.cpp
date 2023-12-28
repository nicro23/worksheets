#include<iostream>
using namespace std;
void twone(int copier ,int array);
void main()
{
    int x[300],j=0,k,min,y[90],i;
    for(i = 0;i<300;i++)
    {
        cin>>x[i];
    }
    i=0;
    for(int k = 0;k<60;k++)
    {
        if(k%2 == 0)
        {
            y[j++] = k[i];
            y[j++] = k[i+1];
            
        }
        else
        {
            y[j++] = k[i];
        }
        i += 5;
        k++;
    }
    min = 9999999999;
    for(int i = 0;i<90;i++)
    {
        if(y[i]<min)
        {
            a1 = y[i];
        }
    }
    min = 999999;
    for(int i = 0;i<300;i++)
    {
        if(x[i]<min)
        {
            a2 = x[i];
        }
    }
    for(i=0;i<300;i++)
    {
        x[i] += a1;
    }
    for(i=0;i<300;i++)
    {
        x[i] -= a2;
    }
    min = 999999;
    twone( y,x);

}
void twone(int copier ,int array)
{

    for(i=0;i<n;i+=10)
    {
        copier[k] = array[i];
        copier[k+1] = array[i+1];
        copier[k+2] = array[i+5];
        k+=3
    }
}