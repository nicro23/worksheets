#include <iostream>
using namespace std;

void main()
{
	int z,x[50],i, pos,min;
	for(int i=0;i<50;i++)
	{
		cin>>x[i];
	}
	
	for(int j = 0; j<50;j++)
	{
		min = 999999;
		for(i = 49;i>=j;i--)
		{
			if(x[i]<min)
			{
				min = x[i];
				pos = i;
			}
		}
		z = x[pos];
		x[pos] = x[j];
		x[j]  = z;

	}
	for(int i=0;i<50;i++)
	{
		cout<<x[i]<<endl;
	}
}