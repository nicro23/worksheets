#include<iostream>
#include<stdio.h>
using namespace std;

struct term
{
    int cof;
    int power;
    int val;
    char name;
};

struct equation
{
    int num_terms;
    term* t;
};

void main()
{
    int i, j, n;
    equation* e;
    cin >> n;
    e = new equation[n];
    for (i = 0; i < n; i++)
    {
        cin >> e[i].num_terms;
        e[i].t = new term[e[i].num_terms];
        for (j = 0; j < e[i].num_terms; j++)
        {
            cin >> e[i].t[j].cof;
            cin >> e[i].t[j].power;
            cin >> e[i].t[j].val;
            cin >> e[i].t[j].name;
        }
    }

    char sel_var_name;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < e[i].num_terms; j++)
        {
            if (e[i].t[j].name == sel_var_name)
            {
                e[i].t[j].cof *= e[i].t[j].power;
                e[i].t[j].power--;
            }
        }
    }
    int sel_power;
    cin >> sel_power;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < e[i].num_terms; j++)
        {
            if (e[i].t[j].name == sel_var_name 
               && e[i].t[j].power == sel_power)
            {
                int x = e[i].t[j].val;
                for (int k = 0; k < e[i].t[j].power; k++)
                {
                    e[i].t[j].val *= x;
                }
                e[i].t[j].val *= e[i].t[j].cof;
                cout << e[i].t[j].val << endl;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        delete[] e[i].t;
    }
    delete[] e;

}