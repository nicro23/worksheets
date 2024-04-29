#include<bits/stdc++.h>
using namespace std; 

int test(int ct,int n,int s, int d,int f)
{
	if (ct == n)
	{
		return f;
	}
	int x, y;
	cin >> x >> y;
	if (x < s && y > d)
	{
		f = 1;
	}
	return test(ct + 1, n, s, d, f);
}
int main()
{
	int n, s, d;
	cin >> n >> s >> d;
	if (test(0,n,s,d,0))
		cout << "Yes";
	else
		cout << "No";
}