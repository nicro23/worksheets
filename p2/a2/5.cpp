#include<iostream>
#include<stdio.h>
using namespace std;

void map(char x[][8])
{
	int r, c;
	char down = 31, back = 92, line_break[22] = "    -----------------";
	cout << "R" << back << "C->1 2 3 4 5 6 7 8" << endl << down << " " << back << "_ ";
	for (c = 0; c < 8; c++)
	{
		cout << down << " ";
	}
	cout << endl;
	for (r = 0; r < 8; r++)
	{
		cout << r + 1<< " "<< "->|";
		for (c = 0; c < 8; c++)
		{
			cout << x[r][c];
			cout << "|";
		}
		if (r < 7)
		{
			cout << endl << line_break;
		}
		cout << endl;
	}
}

void kill(char x[][8], int sel_row, int sel_col, int turn,int &condition)
{
	int i,right_dia,left_dia,j;
	right_dia = sel_row + sel_col - 2;
	left_dia = sel_row - sel_col;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i + j) == right_dia && i != (sel_row -1) && x[i][j] == 'Q')
			{
				cout << "queen of " << turn + 1 << "(" << sel_row << "," << sel_col << ") checks queen at: " << endl << "row: " << i + 1 << " col: " << j + 1 << endl;
				condition = 1;
			}
			if ((i - j) == left_dia && i != (sel_row - 1) && x[i][j] == 'Q')
			{
				cout << "queen of " << turn + 1 << "(" << sel_row << "," << sel_col << ") checks queen at: " << endl << "row: " << i + 1 << " col: " << j + 1 << endl;
				condition = 1;
			}
		}
		if (x[sel_row - 1][i] == 'Q' && i != (sel_col -1))
		{
			cout << "queen of " << turn + 1 << "(" << sel_row << "," << sel_col << ") checks queen at: " << endl << "row: " << sel_row << " col: " << i + 1 << endl;
			condition = 1;
		}
		if (x[i][sel_col - 1] == 'Q' && i != (sel_row - 1))
		{
			cout << "queen of " << turn+1 << "(" << sel_row << "," << sel_col << ") checks queen at: " << endl << "row: " << i +1 << " col: " << sel_col << endl;
			condition = 1;
		}
	}
}

void check(char x[][8], int &turn, int sel_row, int sel_col, char c, int &condition)
{
	int fail = 0;
	char newl[26] = "~~~~~~~~~~~~~~~~~~~~~";
	if (sel_row < 8 + 1 && sel_row > 0 && sel_col < 8 + 1 && sel_col > 0)
	{
		if (x[sel_row - 1][sel_col - 1] == ' ')
		{
			x[sel_row - 1][sel_col - 1] = c;
			kill(x, sel_row, sel_col, turn, condition);
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
		int k = 21;
		while (k--)
		{
			cout << "!";
		}
		cout << endl;
		cout << "!  NOT EMPTY! >:(   !" << endl;
		k = 21;
		while (k--)
		{
			cout << "!";
		}
		cout << endl;
		cout << newl << endl;
		turn--;
	}
}

void main()
{
	char x[8][8];
	int r, c, turn, sel_row, sel_col, condition = 0;;
	for (r = 0; r < 8; r++)
	{
		for (c = 0; c < 8; c++)
		{
			x[r][c] = ' ';
		}
	}
	for (turn = 0; turn < 8; turn++)
	{
		cout << "enter row of queen(starting from 1): " << endl;
		cin >> sel_row;
		cout << "enter col of queen(starting from 1): " << endl;
		cin >> sel_col;
		check(x, turn, sel_row, sel_col, 'Q', condition);
		map(x);
	}
	if (condition == 0)
	{
		cout << "YOU WIN!";
	}
	else
	{
		cout << ":(";
	}
}