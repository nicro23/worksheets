#include<iostream>
using namespace std;
void map(char x[][40])
{
	int r, c;
	char down = 31, back = 92, line_break[86] = "    ---------------------------------------------------------------------------------";
	cout << "R" << back << "C->1 2 3 4 5 6 7 8 9 1[1 2 3 4 5 6 7 8 9 2[1 2 3 4 5 6 7 8 9 3[1 2 3 4 5 6 7 8 9 4[" << endl << down << " " << back << "_ ";
	for (c = 0; c < 40; c++)
	{
		cout << down << " ";
	}
	cout << endl;
	for (r = 0; r < 20; r++)
	{
		cout << r + 1;
		if (r + 1 < 10)
		{
			cout << " ";
		}
		cout << "->|";
		for (c = 0; c < 40; c++)
		{
			cout << x[r][c];
			cout << "|";
		}
		if (r < 19)
		{
			cout << endl << line_break;
		}
		cout << endl;
	}
}
void check(char x[][40],int &turn,int sel_row,int sel_col, char c)
{
	int fail = 0;
	char newl[86] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	if (sel_row < 20 + 1 && sel_row > 0 && sel_col < 40 + 1 && sel_col > 0)
	{
		if (x[sel_row - 1][sel_col - 1] == ' ')	
		{
			x[sel_row - 1][sel_col - 1] = c;
		}
		else
		{
			fail = 1;
		}
	}
	else
	{
		fail = 1;
	}
	if (fail == 1)
	{
		int k = 85;
		while (k--)
		{
			cout << "!";
		}
		cout << endl;
		cout << "!                                  NOT EMPTY! >:(                                   !" << endl;
		cout << newl << endl;
		turn--;
	}
}
void cord(int pos[][2],char dir,int &sel_row, int &sel_col)
{
	int cur_row = pos[0][0], cur_col = pos[0][1];
	if (dir == 'u')
	{
		sel_row = cur_row-1;
		sel_col = cur_col;
	}
	if (dir == 'd')
	{
		sel_row = cur_row+1;
		sel_col = cur_col;
	}
	if (dir == 'l')
	{
		sel_row = cur_row;
		sel_col = cur_col-1;
	}
	if (dir == 'r')
	{
		sel_row = cur_row;
		sel_col = cur_col+1;
	}
}
void main()
{
	char x[20][40], dir;
	int i, r, c, num_obs, sel_row, sel_col,num_apple, snake_size, pos[5][2], condition = 0, useless, temp_row,temp_col;
	//fill matrix with spaces
	for (r = 0; r < 20; r++)
	{
		for (c = 0; c < 40; c++)
		{
			x[r][c] = ' ';
		}
	}
	//add obstacles
	map(x);
	cout << "enter number of obstacles to be added:" << endl;
	cin >> num_obs;
	for(i=0;i<num_obs;i++)
	{
		cout << "enter row of obstacle(starting from 1): " << endl;
		cin >> sel_row;
		cout << "enter col of obstacle(starting from 1):" << endl;
		cin >> sel_col;
		check(x, i, sel_row, sel_col, '#');
		map(x);
	}
	//add apple
	num_apple = 1;
	for(i=0;i<num_apple;i++)
	{
		cout << "enter row of apple(starting from 1): " << endl;
		cin >> sel_row;
		cout << "enter col of apple(starting from 1):" << endl;
		cin >> sel_col;
		check(x, i, sel_row, sel_col, '@');
		map(x);
	}
	//add snake
	snake_size = 5;
	for (i = 0; i < snake_size; i++)
	{
		cout << "enter snake's part "<<i+1<<" (starting from 1)row: " << endl;
		cin >> sel_row;
		cout << "enter snake's part "<<i+1<<" (starting from 1)col: " << endl;
		cin >> sel_col;
		check(x, i, sel_row, sel_col,'~');
		pos[i][0] = sel_row;
		pos[i][1] = sel_col;
		map(x);
	}
	//move the snake
	while (1)
	{
		useless = 0;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "enter direction(u for up, d for down, l for left, r for right): " << endl;
		cin >> dir;
		cord(pos, dir, sel_row, sel_col);
		if (x[sel_row-1][sel_col-1] == '@')
		{
			break;
		}
		check(x, useless, sel_row, sel_col, '~');
		if (useless == 0)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			x[(pos[4][0] -1)][(pos[4][1] -1)] = ' ';
			for (int i = 3; i > 0 -1; i--)
			{
				pos[i+1][0] = pos[i][0];
				pos[i+1][1] = pos[i][1];
			}
			pos[0][0] = sel_row;
			pos[0][1] = sel_col;
		}
		map(x);
	}
	cout << "YOU WON!";
}