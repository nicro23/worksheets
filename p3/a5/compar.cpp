
#include<stdio.h>
#include<iostream>
using namespace std;

class cboard {
public:
    int board[2][6];
    int bt;
    int cash[3];
    char history[200];
    cboard* next;
    cboard()
    {
        for(int i = 0; i < 6; i++)
        {
            if(i < 3)
            {
                cash[i] = 0;
            }
            board[0][i] = 0;
            board[1][i] = 0;
        }
        bt = 0;
        next = NULL;
    }
    cboard(cboard* pnn)
    {

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                board[i][j] = pnn->board[i][j];
            }
        }
        bt = pnn->bt;
        for(int i = 0; i < 3; i++)
        {
            cash[i] = pnn->cash[i];
        }
        for(int i = 0; pnn->history[i] != '\0'; i++)
        {
            history[i] = pnn->history[i];
            if(pnn->history[i + 1] == '\0')
            {
                history[i + 1] = '\0';
            }
        }
    }
};

class cstack {
public:
	cboard* head;
	int ct;
	cstack()
	{
		head = NULL;
		ct = 0;
	}
	void push(cboard* pnn)
	{
		pnn->next = head;
		head = pnn;
		ct++;
	}
	cboard* pop()
	{
		if (head == NULL)
		{
			return NULL;
		}
		ct--;
		cboard* trav = head;
		head = head->next;
		trav->next = NULL;
		return trav;
	}
	/* ~cboard()
	{

	} */
};

cboard* init(cboard* pnn, int c1, int c2, int c3)
{
    pnn = new cboard;
    int x;
    for (int i = 0; i < 6; i++)
    {
        if (i == 0)
        {
            x = 1;
        }
        else
        {
            x = 0;
        }
        for (int j = 0; j < 6; j++)
        {
            pnn->board[i][j] = x;
        }
    }
    pnn->cash[0] = c1;
    pnn->cash[1] = c2;
    pnn->cash[2] = c3;
    return pnn;
}

void disp(cboard* pnn)
{
    cout<<"|m1|m2|m3|c1|c2|c3|"<<endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "|";
		for (int j = 0; j < 6; j++)
		{
			cout << pnn->board[i][j] << '|';
		}
		cout << endl;
		for (int k = 0; k < 6; k++)
		{
			cout << "--";
		}
		cout << endl;
	}
    // cout<<"|"<<c1<<"|"<<c2<<"|"<<c3<<"|";
}

void disp_st(cstack s)
{
	cboard* trav = s.head;
	while (trav != NULL)
	{
		disp(trav);
		for (int k = 0; k < 6; k++)
		{
			cout << "**";
		}
		cout << "*" << endl;
		trav = trav->next;
	}
}

int is_good(cboard* pnn)
{
    int tot_m = 0, tot_c = 0;
	for(int i = 0; i < 3;i++)
    {
        if(pnn->board[0][i] == 1)
        {
            tot_m += pnn->cash[i];
        }
        if(pnn->board[0][i + 3] == 1)
        {
            tot_c += pnn->cash[i];
        }
    }
    if(tot_m != tot_c)
    {
        return 0;
    }
	return 1;
}
int same(cboard* s, cboard* t)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (s->board[i][j] != t->board[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
int exist_st(cstack s, cboard* t, int n)
{
	cboard* trav = s.head;
	while (trav != NULL)
	{
		if (same(trav, t))
		{
			return 1;
		}
		trav = trav->next;
	}
	return 0;
}
void expand(cstack& s, cboard* trav, int n, cstack& good,char f)
{
	cboard* pnn = NULL;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pnn = new cboard(trav, n);
			if (pnn->board[i][j] == ' ')
			{
				pnn->board[i][j] = f;
				pnn->ct++;
			}
			if (is_good(pnn, i, j, n, f) && exist_st(s, trav, n))
			{
				if (pnn->ct == n*n)
				{
					good.push(pnn);
				}
				else 
				{
					s.push(pnn);
				}
			}
		}
	}
}
int main()
{
	int n, f;
	int i = 0;
	cstack s, good;
	cboard* pnn = NULL;
	pnn = init(pnn);
    disp(pnn);
// 	pnn->ct = 0;
// 	s.push(pnn);
// 	cboard* trav = s.pop();
// 	while (trav != NULL)
// 	{
// 		disp(trav, n);
// 		if (i % 2 == 0)
// 		{
// 			expand(s, trav, n, good, 'w');
// 		}
// 		else
// 		{
// 			expand(s, trav, n, good, 'b');
// 		}
// 		trav = s.pop();
// 		i++;
// 	}
// 	disp_st(good, n);
// 	cout << good.ct;
// 	//pop
// 	//expand children
// 	//push if legal

// //    disp(pnn, n);

}