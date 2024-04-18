#include<iostream>
using namespace std;
void map(char x[][3])
{
	int r, c;
	char down = 31, back = 92;
	cout << "R" << back << "C->1 2 3" << endl << down << " " << back << "_ " << down << " " << down << " " << down << endl;
	for (r = 0; r < 3; r++)
	{
		cout << r + 1 << " ->|";
		for (c = 0; c < 3; c++)
		{
			cout << x[r][c];
			cout << "|";
		}
		if (r < 2)
		{
			cout << endl << "    -------";
		}
		cout << endl;
	}
}
void plyr(int t, char& p)
{
	if (t % 2 == 0)
	{
		p = 'X';
	}
	else
	{
		p = 'O';
	}
}
void check_win(char x[][3], int sr, int sc, int& condition, char p)
{
	int ct_row = 0, ct_col = 0, i, ct_left_diagonal = 0, ct_right_diagonal = 0;
	for (i = 0; i < 3; i++)
	{
		if (x[sr - 1][i] == p)
		{
			ct_row++;
		}
		if (x[i][sc - 1] == p)
		{
			ct_col++;
		}
		if (sr + sc == 4)
		{
			if (x[i][2 - i] == p)
			{
				ct_left_diagonal++;
			}
		}
		if (sr == sc)
		{
			if (x[i][i] == p)
			{
				ct_right_diagonal++;
			}
		}
	}
	if (ct_col == 3 || ct_row == 3 || ct_left_diagonal == 3 || ct_right_diagonal == 3)
	{
		condition = 1;
	}
}
int main()
{
	int t, pos_row, pos_col, r, c, condition = 0;
	char x[3][3], p, newl[14] = "~~~~~~~~~~~~~";
	for (r = 0; r < 3; r++)
	{
		for (c = 0; c < 3; c++)
		{
			x[r][c] = ' ';
		}
	}
	for (t = 0; t < 9; t++)
	{
		map(x);
		plyr(t, p);
		cout << newl << endl << "enter row(start from 1): " << endl;
		cin >> pos_row;
		cout << "enter col(start from 1): " << endl;
		cin >> pos_col;
		cout << newl << endl;
		if (x[pos_row - 1][pos_col - 1] == ' ' && pos_row < 3 + 1 && pos_row > 0 && pos_col < 3 + 1 && pos_col > 0)
		{
			x[pos_row - 1][pos_col - 1] = p;
			check_win(x, pos_row, pos_col, condition, p);
			if (condition == 1)
			{
				break;
			}
		}
		else
		{
			cout << "!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "! NOT EMPTY!! >:( !" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!" << endl;
			cout << newl << endl;

			t--;
		}
	}
	map(x);
	if (condition == 1)
	{
		cout << "-----------------" << endl << p << " Player winssssss!!!!!!!";
	}
	else
	{
		cout << newl << endl << "----T.I.E----";
	}
}