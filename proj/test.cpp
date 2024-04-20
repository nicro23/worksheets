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
void clrdraw(char x[][166], int mat_r, int mat_c, int usr_r, int usr_c, int enmy1_r, int enmy1_c)
{
	int i, j, k;
	clear(x, mat_r, mat_c);
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
}
void user_action(char x[][166], char dir, int& r, int& c, int mat_r, int mat_c,int &usr_r,int &usr_c,int &enmy1_r,int &enmy1_c)
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
	if (dir == 'e')
	{
		for (int i = 1; i < 6; i++)
		{
			clrdraw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
			if((x[r][c+i]!= 2))
			{
				x[r][c + i] = '>';
				if((i-1)>0)
				{
					x[r][c + i - 1] = '-';
				}
			}
			else
			{

			}
			map(x, mat_r, mat_c);
		}
	}
	if (dir == 'f')
	{
		for (int i = 1; i < 6; i++)
		{
			clrdraw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
			if((x[r][c+i] != 2))
			{
				x[r][c + i] = '>';
				if((i-1)>0)
				{
					for (int j = 1; j < i; j++)
					{
						x[r][c + j] = '-';
					}
				}
				map(x, mat_r, mat_c);
			}
			else
			{
				
				//sudden >:)
				usr_c+= i-1;
				clrdraw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
				map(x, mat_r, mat_c);
				usr_c += 2;
				clrdraw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
				x[r - 1][usr_c - 2] = 92;
				x[r][usr_c - 1] = 92;
				x[r + 1][usr_c] = 92;
				enmy1_r = -1;
				map(x, mat_r, mat_c);
				break;

				//animation
					//for(k=1;k<i;k++)
					// usr_c++;
					//clrdraw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
					//x[r][c + i] = '>';
					//	map(x, mat_r, mat_c);
			}
		}
	}
}
void main()
{
	int mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c;
	char x[45][166];
	mat_r = 45;
	mat_c = 166;
	usr_r = 22;
	usr_c = 80;
	enmy1_r = 22;
	enmy1_c = 88;
	while (true)
	{
		while (!_kbhit())
		{
			clrdraw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
			map(x, mat_r, mat_c);
		}
		char move = _getch();
		user_action(x, _getch(), usr_r, usr_c, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
	}
}