#include<iostream>
using namespace std;

void main()
{
	int i, j, k, l, n, pos_i, pos_j;
	int** x, **y;
	cin >> n;
	x = new int* [n];
	for (i = 0; i < n; i++)
	{
		x[i] = new int[n];
		for (j = 0; j < n; j++)
		{
			cin >> x[i][j];
		}
	}
	cout << "XD";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (x[i][j] == -1)
			{
				pos_i = i;
				pos_j = j;
				break;
			}
		}
		if (x[i][j] == -1)
		{
			break;
		}
	}
	int diag_diff, st_i, st_j, sz_i, sz_j;
	diag_diff = i - j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if ((i - j) == diag_diff)
			{ 
				break;
			}
		}
		if ((i - j) == diag_diff)
		{
			break;
		}
	}
	st_i = i;
	st_j = j;
	sz_i = pos_i - st_i + 1;
	sz_j = pos_j - st_j + 1;
	y = new int*[sz_i];
	int ct = 0;
	k = 0;
	for ( ; i < pos_i + 1; i++)
	{
		l = 0;
		y[ct] = new int[(sz_j - ct)];
		for (j = st_j; j < pos_j + 1; j++)
		{
			y[ct][l++] = x[i][j];
		}
		ct++;
	}
	ct = 0;
	for (i = 0; i < sz_i; i++)
	{
		for (l = 0; l < ct; l++)
		{
			cout << ".";
		}
		for (j = ct; j < sz_j; j++)
		{
			cout<< y[i][j]<< " ";
		}
		cout << endl;
		ct++;
	}
	for (i = 0; i < n;i++)
	{
		delete[] x[i];
	}
	delete[] x;
	for (i = 0; i < sz_i; i++)
	{
		delete y[i];
	}
	delete y;
}
