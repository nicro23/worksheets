#include<stdio.h>
#include<iostream>
using namespace std;

class cboard {
public:
    int board[2][6];
    int bt;
    cboard* next;
    cboard()
    {
        next = NULL;
    }
    cboard(cboard* pnn)
    {
        bt = pnn->bt;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                board[i][j] = pnn->board[i][j];
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

cboard* init(cboard* pnn, int mx)
{
    int x;
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            x = 1;
        }
        else
        {
            x = 0;
        }
        for (int j = 0; j < 4 - 1; j++)
        {
            pnn->board[i][j] = x;
        }
    }
    //total money here
    pnn->board[0][3] = mx;
    return pnn;
}

void disp(cboard* pnn,int n)
{
    for (int k = 0; k < n; k++)
    {
        cout << "--";
    }
    cout << "-"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < n; j++)
        {
            cout<< pnn->board[i][j]<<'|';
        }
        cout << endl<<"-";
        for (int k = 0; k < n; k++)
        {
            cout << "--";
        }
        cout << endl;
    }
}

void disp_st(cstack s, int n)
{
    cboard* trav = s.head;
    while (trav != NULL)
    {
        disp(trav, n);
        for (int k = 0; k < n; k++)
        {
            cout << "**";
        }
        cout<<"*"<<endl;
        trav = trav->next;
    }
}

int is_good(cboard* pnn, int i, int n)
{
    int cur_row = pnn->cr - 1;
    int cur_col = i;
    int right_dia = cur_row + cur_col;
    int left_dia = cur_row - cur_col;
    for(int j = 0;j<n;j++)
    {
        for(int k = 0;k<n;k++)
        {
            if(pnn->board[j][k] =='Q' && (j+k) == right_dia && j != cur_row)
            {
                return 0;
            }
            if(pnn->board[j][k] =='Q' && (j-k) == left_dia && j != cur_row)
            {
                return 0;
            }
        }
        if(pnn->board[j][cur_col] =='Q' && j != cur_row)
        {
            return 0;
        }
        if(pnn->board[cur_row][j] =='Q' && j != cur_col)
        {
            return 0;
        }
    }
    return 1;
}
void expand(cstack& s, cboard* trav,int n, cstack& good)
{
    cboard* pnn = NULL;
    for (int i = 0; i < n; i++)
    {
        pnn = new cboard(trav, n);
        pnn->board[pnn->cr++][i] = 'Q';
        if(is_good(pnn, i, n))
        {
            if(pnn->cr == n) {
                good.push(pnn);
            }
            else {
                s.push(pnn);
            }
        }
    }
}
int main()
{
    int n;
    cstack s, good;
    cboard* pnn = NULL;
    cin >> n;
    pnn = init(pnn, n);
    pnn->cr = 0;
    s.push(pnn);
    cboard* trav = s.pop();
    while (trav != NULL)
    {
    expand(s, trav, n, good);
    trav = s.pop();
    }
    disp_st(good, n);
    cout<<good.ct;
    //pop
    //expand children
    //push if legal

//    disp(pnn, n);

}