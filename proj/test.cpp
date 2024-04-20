#include <iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

void clear(char x[][166], int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			x[i][j] = ' ';
		}
	}
}

void map(char x[][166], int r, int c)
{
	int i, j;
	system("cls");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			cout << x[i][j];
		}
	}
	cout.flush();

}
void main()
{
	int i, j, k, r, c;
	char x[45][166];
	r = 45;
	c = 166;
	while (true)
	{
		while (!_kbhit())
		{
			clear(x, r, c);
			//prototype fixed objects
			for (i = 0; i < c; i++)
			{
				x[0][i] = '-';
				x[44][i] = '-';
			}
			for (j = 1; j + 1 < r; j++)
			{
				x[j][0] = '|';
				x[j][165] = '|';
			}
			x[22][42] = 1;
			map(x, r, c);
		}
		char move = _getch();
	}
}