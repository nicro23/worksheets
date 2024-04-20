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
void user_action(char x[][166],char dir, int& r, int& c, int mat_r, int mat_c)
{
	if (dir == 'w')
	{
		r--;
	}
	if (dir == 's')
	{
		r++;
	}
	if (dir == 'a')
	{
		c--;
	}
	if (dir == 'd')
	{
		c++;
	}
	if (dir == 'f')
	{
		for (int i = 1; i < 6; i++)
		{
			x[r][c+i] = '>';
			x[r][c + i - 1] = '-';
			map(x,mat_r,mat_c);
		}
	}
}
void all(char x[][166],int mat_r,int mat_c,int usr_r,int usr_c,int enmy1_r,int enmy1_c)
{
	int i, j, k;
	clear(x,mat_r,mat_c);
	//prototype fixed objects
	for (i = 0; i < mat_c; i++)
	{
		x[0][i] = '-';
		x[44][i] = '-';
	}
	for (j = 1; j + 1 < mat_r; j++)
	{
		x[j][0] = '|';
		x[j][165] = '|';
	}
	//prototype moving objects
	x[usr_r][usr_c] = 1;
	x[enmy1_r][enmy1_c] = 2;
	map(x, mat_r, mat_c);
}
void main()
{
	int mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c;
	char x[45][166];
	mat_r = 45;
	mat_c = 166;
	usr_r = 22;
	usr_c = 42;
	enmy1_r = 22;
	enmy1_c = 88;
	while (true)
	{
		while (!_kbhit())
		{
			all(x,mat_r,mat_c,usr_r,usr_c,enmy1_r,enmy1_c);
		}
		char move = _getch();
		user_action(x, _getch(), usr_r, usr_c, mat_r, mat_c);
	}
}