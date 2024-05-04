#include <iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

void clear(char x[][166], int mat_r, int mat_c)
{
	//clear the matrix
	int i, j;
	for (i = 0; i < mat_r; i++)
	{
		for (j = 0; j < mat_c; j++)
		{
			x[i][j] = ' ';
		}
	}
}
void map(char x[][166], int mat_r, int mat_c)
{
	//screen the matrix
	int i, j;
	system("cls");
	for (i = 0; i < mat_r; i++)
	{
		for (j = 0; j < mat_c; j++)
		{
			cout << x[i][j];
		}
	}
	cout.flush();

}
void draw_hero(char x[][166], int usr_r, int usr_c)
{
	//draw hero ["center of gravity" = mouth]
	/*
	hero properties:

	*/
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
	//-------//
	//prototype moving objects
	/* proto frame 1
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
	*/
}
void draw_fixed(char x[][166], int mat_r, int mat_c)
{
	int i, j, k;
	//draw roof&floor
	for (i = 0; i < mat_c; i++)
	{
		x[0][i] = '-';
		x[44][i] = '-';
	}
	//draw borders
	for (j = 1; j + 1 < mat_r; j++)
	{
		x[j][0] = '|';
		x[j][165] = '|';
	}
}
void draw_platform(char x[][166], int platform_r, int platform_c)
{
	//stair change place to variables 
	for (int i = 0; i < 10; i++)
	{
		x[platform_r][platform_c] = 205;
	}
}
void draw_enemy1(char x[][166], int enemy1_r, int enemy1_c)
{
	x[enemy1_r][enemy1_c] = 2;
}
void draw_bullets(char x[][166], int bullets_pos[][2], int ct_bullet)
{
	//loop over number of bullets
	while (ct_bullet)
	{
		//draw bullet in the x & y contained in bullets_pos array
		x[(bullets_pos[ct_bullet][0])][(bullets_pos[ct_bullet][1])] = '>';
		//if infront of bullet is space

		//go to previous bullet
		ct_bullet--;
	}
}
void move_bullets(char x[][166], int bullets_pos[][2], int &ct_bullet)
{
	//reload bullet algoritihim
	// write code here
	//infinite bullets
	// make dummy count
	int ct_bullet_tmp = ct_bullet;
	//loop over number of bullets
	while (ct_bullet_tmp)
	{
		//if infront of bullet is space
		if ((x[bullets_pos[ct_bullet_tmp][0]][bullets_pos[ct_bullet_tmp][1] + 1]) == ' ')
		{
			//move bullet position to the next col
			bullets_pos[ct_bullet_tmp][1]++;
		}
		else
		{
			//shift backwards
			for (int i = ct_bullet_tmp; i < ct_bullet; i++)
			{
				//shift row
				bullets_pos[i][0] = bullets_pos[i + 1][0];
				//shift col
				bullets_pos[i][1] = bullets_pos[i + 1][1];
			}
			//minus actual count of bullet
			ct_bullet--;
			/*
			//shift backwards
			for (int i = ct_bullet_tmp; i < ct_bullet; i++)
			{
				bullets_pos[i][1] = bullets_pos[i + 1][1];
			}
			ct_bullet--;
			*/
		}
		//move to the previous bullet
		ct_bullet_tmp--;
	}
	/*
	turret?
	while (ct_bullet--)
	{
		//if infront of bullet is space
		if ((bullets_pos[ct_bullet][0] + 1) == ' ')
		{
			//move bullet position to the next col
			bullets_pos[ct_bullet][0]++;
		}
		else
		{
			//make bullet col = -1
			bullets_pos[ct_bullet][0] = -1;
		}
	}*/
}
void user_action(char x[][166], char dir, int& usr_r, int& usr_c, int mat_r, int mat_c, int& enemy1_r, int& enemy1_c,int platform_r, int platform_c, int bullets_pos[][2],int &ct_bullet)
{
	//move up if user pressed w
	if (dir == 'w')
	{
		usr_r--;
	}
	//move down if user pressed s
	if (dir == 's')
	{
		usr_r++;
	}
	//move left if user pressed a
	if (dir == 'a')
	{
		usr_c--;
	}
	//move right if user pressed d
	if (dir == 'd')
	{
		usr_c++;
	}
	//gets the gun's row {subject to change}
	int gun_r = usr_r + 2;
	//gets the gun's col {subject to change}
	int gun_c = usr_c + 4;
	//shoot an arrow if user pressed e
	if (dir == 'e')
	{
		ct_bullet++;
		bullets_pos[ct_bullet][0] = gun_r;
		bullets_pos[ct_bullet][1] = gun_c + 1;
	}
	//shoot grapple hook
	if (dir == 'f')
	{
		for (int i = 1; i < 6; i++)
		{
			//clear map
			clear(x, mat_r, mat_c);
			//redraw map
			draw_fixed(x, mat_r, mat_c);
			draw_platform(x, platform_r, platform_c);
			draw_enemy1(x, enemy1_r, enemy1_c);
			draw_hero(x, usr_r, usr_c);
			//checks collision [currently checks with enemy1 only]
			if ((x[gun_r][gun_c + i] != 2))
			{
				//throws grapple
				x[gun_r][gun_c + i] = '>';
				if ((i - 1) > 0)
				{
					for (int j = 1; j < i; j++)
					{
						x[gun_r][gun_c + j] = '-';
					}
				}
			map(x, mat_r, mat_c);
			}
			else
			{
				//if you catched enemy
				//(sudden >:) animation)
				//move&display hero to infront of enemy
				usr_c += i - 1;
				clear(x, mat_r, mat_c);
				//redraw map
				draw_fixed(x, mat_r, mat_c);
				draw_platform(x, platform_r, platform_c);
				draw_enemy1(x, enemy1_r, enemy1_c);
				draw_hero(x, usr_r, usr_c);
				map(x, mat_r, mat_c);
				//draw hero behind enemy
				usr_c += 11;
				clear(x, mat_r, mat_c);
				//redraw map
				draw_fixed(x, mat_r, mat_c);
				draw_platform(x, platform_r, platform_c);
				draw_enemy1(x, enemy1_r, enemy1_c);
				draw_hero(x, usr_r, usr_c);
				//draw hit animation
				x[gun_r - 2][usr_c - 8] = 92;
				x[gun_r - 1][usr_c - 7] = 92;
				x[gun_r][usr_c - 6] = 92;
				x[gun_r + 1][usr_c - 5] = 92;
				x[gun_r + 2][usr_c - 4] = 92;
				//kill enemy
				enemy1_r = -1;
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
	//combo 1 para: (int mat_r,int mat_c,int usr_r,int usr_c,int enemy1_r,int enemy1_c,platform_r,int platform_c)
	int mat_r, mat_c;
	int usr_r, usr_c;
	int enemy1_r, enemy1_c;
	int platform_r, platform_c;
	int bullets_pos[100][2], ct_bullet = 0;
	char x[45][166];
	//size of mat
	mat_r = 45;
	mat_c = 166;
	//usr position
	usr_r = 22;
	//usr_c = 80;
	usr_c = 150;
	//enemy1 position
	enemy1_r = 22;
	enemy1_c = 88;
	//platform position
	platform_r = 22;
	platform_c = 70;
	//infinite loop
	while (true)
	{
		//loop till keyboard is hit
		while (!_kbhit())
		{
			//clear matrix to redraw
			clear(x, mat_r, mat_c);
			//draw fixed background [current: roof, floor]
			draw_fixed(x, mat_r, mat_c);
			//draw combo1 [platform,enemy1,hero]
			//draw platform
			draw_platform(x, platform_r, platform_c);
			//draw enemy 1
			draw_enemy1(x, enemy1_r, enemy1_c);
			//move then draw bullet
			move_bullets(x, bullets_pos, ct_bullet);
			draw_bullets(x, bullets_pos, ct_bullet);
			//draw hero
			draw_hero(x, usr_r, usr_c);
			//screen the matrix
			map(x, mat_r, mat_c);
		}
		//save user input
		char move = _getch();
		//take action based on input
		user_action(x, move, usr_r, usr_c, mat_r, mat_c, enemy1_r, enemy1_c, platform_r, platform_c, bullets_pos, ct_bullet);
	}
}