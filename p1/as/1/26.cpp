#include<iostream>
using namespace std;

void main()
{
    int x[30], min=9999999;
    float tot=0, avg;
    for(int i =0;i<30;i++)
    {
        cin>>x[i];
    }
    for(int i =0;i<30;i+=10)
    {
        for(int j =0;j<10;j++)
        {
            if(x[j+i] <min)
            {
                min = x[i+j];
            }
            tot+= x[i+j];
        }
        avg = tot/10;
        cout<<min<<endl<<avg<<endl;
        for(int j=0;j<10;j++)
        {
            if(x[j+i]>avg)
            {
                cout<<x[j+i]<<endl;
            }
        }
    }
}
// 0-9 ; 10-19 ; 20-29