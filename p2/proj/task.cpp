#include<iostream>
#include<stdio.h>
using namespace std;

struct player
{
	char name;
	int score;
	int rank;
	int color;
};

struct game
{
	char board[3][3];
	player p[2];
};
void main()
{
	int n;
	cin >> n;
	game* g;
	g = new game[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cin >> g[i].board[j][k];
			}
		}
		for (int l = 0; l < 2; l++)
		{
			cin >> g[i].p[l].name;
			cin >> g[i].p[l].score;
			cin >> g[i].p[l].rank;
			cin >> g[i].p[l].color;
		}
	}
	int sel_g;
	char win;
	cin >> sel_g;
	for (int i = 0; i < 3; i++)
	{
        if(g[sel_g].board[i][0] == g[sel_g].board[i][1] && g[sel_g].board[i][0] == g[sel_g].board[i][2])
        {
            win = g[sel_g].board[i][0];
        }
        if(g[sel_g].board[0][i] == g[sel_g].board[1][i] && g[sel_g].board[0][i] == g[sel_g].board[2][i])
        {
            win = g[sel_g].board[0][i];
        }
        if(g[sel_g].board[0][0] == g[sel_g].board[1][1] && g[sel_g].board[0][0] == g[sel_g].board[2][2])
        {
            win = g[sel_g].board[0][0];
        }
        if(g[sel_g].board[0][2] == g[sel_g].board[1][1] && g[sel_g].board[0][2] == g[sel_g].board[2][0])
        {
            win = g[sel_g].board[0][2];
        }
	}
    cout<< win;
}
