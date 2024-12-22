
#include<stdio.h>
#include<iostream>
using namespace std;

class cboard {
public:
    int board[2][6];
    int move_to;
    int cash[3];
    char history[200];
    //index for history string
    int iWhere;
    cboard* next;
    cboard()
    {
        for (int a = 0; a < 6; a++)
        {
            if (a < 3)
            {
                cash[a] = 0;
            }
            board[0][a] = 0;
            board[1][a] = 0;
        }
        move_to = 1;
        this->iWhere = 0;
    }
    cboard(cboard* pnn)
    {

        for (int r = 0; r < 2; r++)
        {
            for (int j = 0; j < 6; j++)
            {
                board[r][j] = pnn->board[r][j];
            }
        }
        move_to = pnn->move_to;
        for (int r = 0; r < 3; r++)
        {
            cash[r] = pnn->cash[r];
        }
        for (int r = 0; pnn->history[r] != '\0'; r++)
        {
            history[r] = pnn->history[r];
            if (pnn->history[r + 1] == '\0')
            {
                history[r + 1] = '\0';
            }
        }
        this->iWhere = pnn->iWhere;
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
    /*~cstack()
    {
        cboard* trav = head;
        while (trav != NULL)
        {
            head = head->next;
            trav->next = NULL;
            delete trav;
            trav = head;
        }
    }*/
};

cboard* init(cboard* pnn, int c1, int c2, int c3)
{
    pnn = new cboard;
    int x;
    // i has to be more than 3??
    for (int a = 0; a < 3; a++)
    {
        if (a == 0)
        {
            x = 1;
        }
        else
        {
            x = 0;
        }
        for (int j = 0; j < 6; j++)
        {
            pnn->board[a][j] = x;
        }
    }
 /*   for (int j = 0; j < 6; j++)
    {
        pnn->board[0][j] = 1;
        pnn->board[1][j] = 0;
    }*/
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
    // not good when the total cash that is present is bigger than the total cash that the men own except if there is no man at shore
    if (tot_c0 > tot_m0 && tot_m0 != 0)
    {
        return 0;
    }
    if (tot_c1 > tot_m1 && tot_m1 != 0)
    {
        return 0;
    }
    return 1;
}
int same(cboard* s, cboard* t)
{
    for (int i = 0; i < 6; i++)
    {
        if (s->board[0][i] != t->board[0][i])
        {
            return 0;
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
            child->history[child->iWhere++] = 'm';
            child->history[child->iWhere++] = '1';
            if (child->move_to == 1)
            {
                child->history[child->iWhere++] = 'd';
            }
            else
            {
                child->history[child->iWhere++] = 'u';
            }
            mv = 1;
        }
        if (((i >= 6 && i < 11) || i == 1) && child->board[child->move_to][1] == 0)
        {
            child->board[child->move_to][1] = 1;
            child->board[x][1] = 0;
            man_on_boat = 1;
            child->history[child->iWhere++] = 'm';
            child->history[child->iWhere++] = '2';
            if (child->move_to == 1)
            {
                child->history[child->iWhere++] = 'd';
            }
            else
            {
                child->history[child->iWhere++] = 'u';

            }
            mv = 1;
        }
        if ((i >= 11 || i == 2 || i == 7) && child->board[child->move_to][2] == 0)
        {
            child->board[child->move_to][2] = 1;
            child->board[x][2] = 0;
            man_on_boat = 1;
            child->history[child->iWhere++] = 'm';
            child->history[child->iWhere++] = '3';
            if (child->move_to == 1)
            {
                child->history[child->iWhere++] = 'd';
            }
            else
            {
                child->history[child->iWhere++] = 'u';
            }
            mv = 1;
        }
        if ((i == 3 || i == 8 || i == 12) && child->board[child->move_to][3] == 0 && man_on_boat == 1)
        {
            child->board[child->move_to][3] = 1;
            child->board[x][3] = 0;
            child->history[child->iWhere++] = 'c';
            child->history[child->iWhere++] = '1';
            if (child->move_to == 1)
            {
                child->history[child->iWhere++] = 'd';
            }
            else
            {
                child->history[child->iWhere++] = 'u';
            }
            mv = 1;
        }
        if ((i == 4 || i == 9 || i == 13) && child->board[child->move_to][4] == 0 && man_on_boat == 1)
        {
            child->board[child->move_to][4] = 1;
            child->board[x][4] = 0;
            child->history[child->iWhere++] = 'c';
            child->history[child->iWhere++] = '2';
            if (child->move_to == 1)
            {
                child->history[child->iWhere++] = 'd';
            }
            else
            {
                child->history[child->iWhere++] = 'u';
            }
            mv = 1;
        }
        if ((i == 5 || i == 10 || i == 14) && child->board[child->move_to][5] == 0 && man_on_boat == 1)
        {
            child->board[child->move_to][5] = 1;
            child->board[x][5] = 0;
            child->history[child->iWhere++] = 'c';
            child->history[child->iWhere++] = '3';
            if (child->move_to == 1)
            {
                child->history[child->iWhere++] = 'd';
            }
            else
            {
                child->history[child->iWhere++] = 'u';
            }
            mv = 1;
        }
        child->history[child->iWhere++] = ',';
        child->history[child->iWhere] = '\0';
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
    cout << "<===================>" << endl;
    disp_st(good);
    cout << good.ct;
    //pop
    //expand children
    //push if legal
    // disp(pnn);

}