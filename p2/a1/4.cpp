#include<iostream>
using namespace std;

void main()
{
	int r, c, p=0, i;
	int x[3][2];
	char s[100];
		for (r = 0; r < 3;r++)
		{
			for (c = 0; c < 2; c++)
			{
				cin >> x[r][c];
			}
		}
	cin >> s;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'a')
		{
			p = x[p][0];
		}
		if (s[i] == 'b')
		{
			p = x[p][1];
		}
	}
	if (p == 2)
	{
		cout << "horray";
	}
	else
	{
		cout << "not horray";
	}
}
