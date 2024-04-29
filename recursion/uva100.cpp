#include<bits/stdc++.h>
using namespace std; 

int ct(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n % 2 == 0)
		return 1 + ct(n / 2);
	return 1 + ct(3 * n + 1);
}
int main()
{
	int i, j, l, max;
	while (cin >> i >> j)
	{
		cout<< i << " " << j << " ";
		if (i > j)
		{
			l = i;
			i = j;
			j = l;
		}
		int max = 0;
		for (int k = i; k <= j; k++)
		{
			int x = ct(k);
			if (x > max)
			{
				max = x;
			}
		}
		cout << max << endl;
	}
}