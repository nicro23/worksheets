
#include<stdio.h>
#include<iostream>
using namespace std;

class cboard {
public:
    int board[2][6];
    int move_to;
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
        move_to = 1;
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
        move_to = pnn->move_to;
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
    for(int i = 0; i < 3; i++)
    {
        cout<<"|"<<pnn->cash[i];
    }
    cout<<"|"<<endl;
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
int is_same(cboard* s, cboard* t)
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
int exist_st(cstack s, cboard* t)
{
	cboard* trav = s.head;
	while (trav != NULL)
	{
		if (is_same(trav, t))
		{
			return 1;
		}
		trav = trav->next;
	}
	return 0;
}

int is_done(cboard* curr)
{
    for(int i = 0; i < 6; i++)
    {
        if(curr->board[1][i] == '0')
        {
            return 0;
        }
    }
    return 1;
}
void expand(cstack& s, cboard* trav, cstack& good)
{
	cboard* pnn = NULL;
    int x;
	for (int i = 0; i < 15; i++)
	{
        pnn = new cboard(trav);
        x = pnn->move_to;
        if(pnn->move_to)
        {
            pnn->move_to = 0;
        }
        else
        {
            pnn->move_to = 1;
        }
        
        if (is_good(pnn) && !(exist_st(s, pnn)))
        {
            if (is_done(pnn))
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

int main()
{
	int c1 = 800,c2 = 500,c3 = 300;
	cstack s, good;
	cboard* pnn = NULL;
    //cin>>c1>>c2>>c3;
	pnn = init(pnn, c1, c2, c3);
    disp(pnn);
	s.push(pnn);
	cboard* trav = s.pop();
	while (trav != NULL)
	{
		disp(trav);
        expand(s, trav, n, good, 'w');
		trav = s.pop();
	}
	disp_st(good);
	cout << good.ct;
	//pop
	//expand children
	//push if legal

    disp(pnn, n);

}