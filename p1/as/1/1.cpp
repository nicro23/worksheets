#include<iostream>
using namespace std;

void main()
{
    int x[50];
    for(int i=0;i<50;i++)
	{
		cin>>x[i];
	}
    for(int j = 0;j<50;j++)
    {
        for(int i = j;i<50;i++)
        {
                cout<<x[j]<<","<<x[i];
        }
    }
    
}