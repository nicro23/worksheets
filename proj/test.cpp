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
void draw_hero(char x[][166],int usr_r,int usr_c)
{
	//draw hero ["center of gravity" = mouth]
	//draw head
	x[usr_r][usr_c] = '-';
	x[usr_r][usr_c + 1] = '*';
	x[usr_r][usr_c - 1] = '*';
	x[usr_r][usr_c + 2] = ']';
	x[usr_r][usr_c - 2] = '[';
	//draw torso
	x[usr_r + 1][usr_c] = 208;//╨
	x[usr_r + 1][usr_c + 1] = 196;//─
	x[usr_r + 1][usr_c - 1] = 196;//─
	x[usr_r + 1][usr_c + 2] = 209;//╤
	x[usr_r + 2][usr_c + 2] = 179;//│
	x[usr_r + 1][usr_c - 2] = 209;//╤
	x[usr_r + 2][usr_c - 2] = 179;//│
	x[usr_r + 3][usr_c] = 196;//─
	x[usr_r + 3][usr_c + 1] = 196;//─
	x[usr_r + 3][usr_c - 1] = 196;//─
	x[usr_r + 3][usr_c + 2] = 180;//┤
	x[usr_r + 3][usr_c - 2] = 195;//├
	//draw right hand("free hand")
	x[usr_r + 1][usr_c - 3] = 218;//┌
	x[usr_r + 2][usr_c - 3] = 179;//│
	x[usr_r + 3][usr_c - 3] = 179;//│
	//draw left hand("gun hand")
	x[usr_r + 1][usr_c + 3] = 191;//┐
	x[usr_r + 2][usr_c + 3] = 192;//└
	x[usr_r + 2][usr_c + 4] = 216;//╪
	//draw left leg("kowsa")
	x[usr_r + 4][usr_c + 2] = 179;//│
	x[usr_r + 5][usr_c + 2] = 179;//│
	//draw right leg("bsl")
	x[usr_r + 4][usr_c - 2] = 179;//│
	x[usr_r + 5][usr_c - 2] = 179;//│
}
void draw(char x[][166], int mat_r, int mat_c, int usr_r, int usr_c, int enmy1_r, int enmy1_c)
{
	int i, j, k;
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
	//stair change place to variables 
	for (i = 0; i < 10; i++)
	{
		x[28][62+i] = 205;
	}
	//prototype moving objects
	x[enmy1_r][enmy1_c] = 2;
	///x[5][10] = "p";
	///x[6][10] = '|';
	///x[5][10] = 248;
	//draw_hero(x, usr_r, usr_c);
	//draw hero ["center of gravity" = mouth]
	//draw head
	x[usr_r][usr_c] = '-';
	x[usr_r][usr_c + 1] = '*';
	x[usr_r][usr_c - 1] = '*';
	x[usr_r][usr_c + 2] = ']';
	x[usr_r][usr_c - 2] = '[';
	//draw torso
	x[usr_r + 1][usr_c] = 208;//╨
	x[usr_r + 1][usr_c + 1] = 196;//─
	x[usr_r + 1][usr_c - 1] = 196;//─
	x[usr_r + 1][usr_c + 2] = 209;//╤
	x[usr_r + 2][usr_c + 2] = 179;//│
	x[usr_r + 1][usr_c - 2] = 209;//╤
	x[usr_r + 2][usr_c - 2] = 179;//│
	x[usr_r + 3][usr_c] = 196;//─
	x[usr_r + 3][usr_c + 1] = 196;//─
	x[usr_r + 3][usr_c - 1] = 196;//─
	x[usr_r + 3][usr_c + 2] = 180;//┤
	x[usr_r + 3][usr_c - 2] = 92;//
	//draw right hand("free hand")
	x[usr_r + 1][usr_c - 3] = 218;//┌
	x[usr_r + 2][usr_c - 3] = 92;// 
	//x[usr_r + 3][usr_c - 3] = 179;//│
	//draw left hand("gun hand")
	x[usr_r + 1][usr_c + 3] = 191;//┐
	x[usr_r + 2][usr_c + 3] = 192;//└
	x[usr_r + 2][usr_c + 4] = 216;//╪
	//draw left leg("kowsa")
	x[usr_r + 4][usr_c + 2] = 92;//
	//x[usr_r + 5][usr_c + 2] = 179;//
	x[usr_r + 5][usr_c + 3] = 92;//
	//draw right leg("bsl")
	x[usr_r + 4][usr_c - 2] = 179;//│
	x[usr_r + 5][usr_c - 2] = 179;//│




}
void user_action(char x[][166], char dir, int& usr_r, int& usr_c, int mat_r, int mat_c,int &enmy1_r,int &enmy1_c)
{
	int r = usr_r + 2;
	int c = usr_c + 4;
	if (dir == 'w')
	{
		usr_r--;
	}
	if (dir == 's')
	{
		usr_r++;
	}
	if (dir == 'a')
	{
		usr_c--;
	}
	if (dir == 'd')
	{
		usr_c++;
	}
	if (dir == 'e')
	{
		for (int i = 1; i < 166; i++)
		{
			clear(x, mat_r, mat_c);
			draw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
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
			clear(x, mat_r, mat_c);
			draw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
			if((x[r][c+i] != 2))
			{
				//throws grapple
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
				//if you catched enemy
				//(sudden >:) animation)
				//move&display hero to infront of enemy
				usr_c+= i-1;
				clear(x, mat_r, mat_c);
				draw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
				map(x, mat_r, mat_c);
				//draw hero behind enemy
				usr_c += 11;
				clear(x, mat_r, mat_c);
				draw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
				//draw hit animation
				x[r - 2][usr_c - 8] = 92;
				x[r - 1][usr_c - 7] = 92;
				x[r][usr_c - 6] = 92;
				x[r + 1][usr_c - 5] = 92;
				x[r + 2][usr_c - 4] = 92;
				//kill enemy
				enmy1_r = -1;
				//display
				map(x, mat_r, mat_c);
				break;

				//animation
					//for(k=1;k<i;k++)
					// usr_c++;
					// clear(x, mat_r, mat_c);
					// 
					// 
					//x[r][c + i] = '>';
					//	map(x, mat_r, mat_c);
			}
		}
	}
	if (usr_r + 6 == 28)
	{
		x[28][65] = 'O';

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
			clear(x, mat_r, mat_c);
			draw(x, mat_r, mat_c, usr_r, usr_c, enmy1_r, enmy1_c);
			map(x, mat_r, mat_c);
		}
		char move = _getch();
		user_action(x, move, usr_r, usr_c, mat_r, mat_c, enmy1_r, enmy1_c);
	}
}