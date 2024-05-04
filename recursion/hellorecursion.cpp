#include<bits/stdc++.h>
using namespace std;

int sum(int x[], int ct, int n)
{
	//base case
	if (ct == 3)
	{
		return n;
	}
	//transition
	n += x[ct];
	sum(x, ct+1, n);
}
int main()
{
	int n,t,y;
	int x[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> x[i];
	}
	cout<<sum(x,0,0);

}