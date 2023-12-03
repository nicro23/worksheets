#include<iostream>
using namespace std;

void main()
{
    int x[5];
    for(int i=0;i<5;i++)
	{
		cin>>x[i];
	}
    for(int j = 0;j<5;j++)
    {
        for(int i = 0;i<5;i++)
        {
            if(x[j]<=x[i])
            {
                cout<<x[j]<<" , "<<x[i]<<endl;
            }
        }
    }
    
}