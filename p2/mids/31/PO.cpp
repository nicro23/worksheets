#include<iostream>
using namespace std;

void main()
{
	int i, j, k, n, m;
	int* zs;
	int** x,**y, **z;
	cin >> m;
	cin >> n;
	x = new int*[m];
	for (i = 0; i < m; i++)
	{
		x[i] = new int[n];
		for (j = 0; j < n; j++) 
		{
			cin >> x[i][j];
		}
	}
	y = new int* [m];
	for (i = 0; i < m; i++)
	{
		y[i] = new int[n];
		for (j = 0; j < n; j++)
		{
			cin >> y[i][j];
		}
	}
	z = new int*[m];
	zs = new int[m];
	int ct, l;
	for (i = 0; i < m; i++)
	{
		ct = 0;
		for (j = 0; j < n; j++)
		{
			if (x[i][j] == 0)
			{
				for (k = j + 1; x[i][k] != 0; k++)
				{
					ct++;
				}
				zs[i] = 2*ct;
				break;
			}
		}
		z[i] = new int[(2*ct)];
		l = 0;
		for (k = j + 1;x[i][k] != 0; k++)
		{
			z[i][l++] = x[i][k];
		}
		for (k = j + 1; x[i][k] != 0; k++)
		{
			z[i][l++] = y[i][k];
		}
	}
	for (i = 0; i < m; i++)
	{
		if(zs[i] == 6)
		for (j = 0; j < 6; j++)
		{
			cout << z[i][j] << " ";
		}
		cout << endl;
	}
	for (i = 0; i < m; i++)
	{
		delete[] x[i];
		delete[] y[i];
		delete[] z[i];
	}
	delete[] x;
	delete[] y;
	delete[] z;
	delete[] zs;

}