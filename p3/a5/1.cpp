
#include<stdio.h>
#include<iostream>
using namespace std;

class cboard {
public:
    int board[2][6];
    int move_to;
    int cash[3];
    char history[200];
    int i;
    cboard* next;
    cboard()
    {
        for (int i = 0; i < 6; i++)
        {
            if (i < 3)
            {
                cash[i] = 0;
            }
            board[0][i] = 0;
            board[1][i] = 0;
        }
        move_to = 1;
        i = 0;
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
        for (int i = 0; i < 3; i++)
        {
            cash[i] = pnn->cash[i];
        }
        for (int i = 0; pnn->history[i] != '\0'; i++)
        {
            history[i] = pnn->history[i];
            if (pnn->history[i + 1] == '\0')
            {
                history[i + 1] = '\0';
            }
        }
        i = pnn->i;
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
    cout << "|m1|m2|m3|c1|c2|c3|" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "|";
        for (int j = 0; j < 6; j++)
        {
            cout << pnn->board[i][j] << " |";
        }
        cout << endl;
        for (int k = 0; k < 10; k++)
        {
            cout << "--";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "|" << pnn->cash[i];
    }
    cout << "|" << endl;
}
void disp_history(cboard* pnn)
{
    for (int i = 0; pnn->history[i] != '\0'; i++)
    {
        cout << pnn->history[i];
    }
    cout << endl;
}
void disp_st(cstack s)
{
    cboard* trav = s.head;
    while (trav != NULL)
    {
        disp(trav);
        disp_history(trav);
        for (int k = 0; k < 10; k++)
        {
            cout << "**";
        }
        cout << endl;
        trav = trav->next;
    }
}

int is_good(cboard* pnn)
{
    int tot_m0 = 0, tot_c0 = 0, tot_m1 = 0, tot_c1 = 0;
    for (int i = 0; i < 3; i++)
    {
        if (pnn->board[0][i] == 1)
        {
            tot_m0 += pnn->cash[i];
        }
        if (pnn->board[0][i + 3] == 1)
        {
            tot_c0 += pnn->cash[i];
        }
        if (pnn->board[1][i] == 1)
        {
            tot_m1 += pnn->cash[i];
        }
        if (pnn->board[1][i + 3] == 1)
        {
            tot_c1 += pnn->cash[i];
        }
    }
    if (tot_m0 < tot_c0 && tot_m0 != 0)
    {
        return 0;
    }
    if (tot_m1 < tot_c1 && tot_m1 != 0)
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
    if (s->move_to != t->move_to)
    {
        return 0;
    }
    return 1;
}
int exist_st(cstack v, cboard* t)
{
    cboard* trav = v.head;
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

int is_done(cboard* curr)
{
    int ct = 0;
    for (int i = 0; i < 6; i++)
    {
        if (curr->board[1][i] == 1)
        {
            ct++;
        }
    }
    if (ct == 6)
    {
        return 1;
    }
    return 0;
}
void expand(cstack& s, cstack& v, cboard* parent, cstack& good)
{
    cboard* child = NULL;
    int x, man_on_boat, mv;
    for (int i = 0; i < 15; i++)
    {
        mv = 0;
        man_on_boat = 0;
        child = new cboard(parent);
        x = child->move_to;
        if (child->move_to)
        {
            child->move_to = 0;
        }
        else
        {
            child->move_to = 1;
        }
        if (i < 6 && child->board[child->move_to][0] == 0)
        {
            child->board[child->move_to][0] = 1;
            child->board[x][0] = 0;
            man_on_boat = 1;
            child->history[child->i++] = 'm';
            child->history[child->i++] = '1';
            if (child->move_to == 1)
            {
                child->history[child->i++] = 'd';
            }
            else
            {
                child->history[child->i++] = 'u';
            }
            mv = 1;
        }
        if (((i >= 6 && i < 11) || i == 1) && child->board[child->move_to][1] == 0)
        {
            child->board[child->move_to][1] = 1;
            child->board[x][1] = 0;
            man_on_boat = 1;
            child->history[child->i++] = 'm';
            child->history[child->i++] = '2';
            if (child->move_to == 1)
            {
                child->history[child->i++] = 'd';
            }
            else
            {
                child->history[child->i++] = 'u';

            }
            mv = 1;
        }
        if ((i >= 11 || i == 2 || i == 7) && child->board[child->move_to][2] == 0)
        {
            child->board[child->move_to][2] = 1;
            child->board[x][2] = 0;
            man_on_boat = 1;
            child->history[child->i++] = 'm';
            child->history[child->i++] = '3';
            if (child->move_to == 1)
            {
                child->history[child->i++] = 'd';
            }
            else
            {
                child->history[child->i++] = 'u';
            }
            mv = 1;
        }
        if ((i == 3 || i == 8 || i == 12) && child->board[child->move_to][3] == 0 && man_on_boat == 1)
        {
            child->board[child->move_to][3] = 1;
            child->board[x][3] = 0;
            child->history[child->i++] = 'c';
            child->history[child->i++] = '1';
            if (child->move_to == 1)
            {
                child->history[child->i++] = 'd';
            }
            else
            {
                child->history[child->i++] = 'u';
            }
            mv = 1;
        }
        if ((i == 4 || i == 9 || i == 13) && child->board[child->move_to][4] == 0 && man_on_boat == 1)
        {
            child->board[child->move_to][4] = 1;
            child->board[x][4] = 0;
            child->history[child->i++] = 'c';
            child->history[child->i++] = '2';
            if (child->move_to == 1)
            {
                child->history[child->i++] = 'd';
            }
            else
            {
                child->history[child->i++] = 'u';
            }
            mv = 1;
        }
        if ((i == 5 || i == 10 || i == 14) && child->board[child->move_to][5] == 0 && man_on_boat == 1)
        {
            child->board[child->move_to][5] = 1;
            child->board[x][5] = 0;
            child->history[child->i++] = 'c';
            child->history[child->i++] = '3';
            if (child->move_to == 1)
            {
                child->history[child->i++] = 'd';
            }
            else
            {
                child->history[child->i++] = 'u';
            }
            mv = 1;
        }
        child->history[child->i++] = ',';
        child->history[child->i] = '\0';
        if (is_good(child) && !(exist_st(v, child)) && mv)
        {
            if (is_done(child))
            {
                good.push(child);
            }
            else
            {
                cboard* unvisited_child = new cboard(child);
                v.push(unvisited_child);
                s.push(child);
            }
        }
        
    }
}

int main()
{
    int c1 = 800, c2 = 500, c3 = 300;
    cstack s, v, good;
    cboard* pnn = NULL;
    //cin>>c1>>c2>>c3;
    pnn = init(pnn, c1, c2, c3);
    //disp(pnn);
    s.push(pnn);
    v.push(pnn);
    cboard* trav = s.pop();
    while (trav != NULL)
    {
        disp(trav);
        expand(s, v, trav, good);
        trav = s.pop();
    }
    disp_st(good);
    cout << good.ct;
    //pop
    //expand children
    //push if legal
    // disp(pnn);

}