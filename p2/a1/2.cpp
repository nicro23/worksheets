#include<iostream>
using namespace std;

void main()
{
    int x[100][100];
    int i, j, not_i = 0;
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            cin >> x[i][j];
        }
    }
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            if ( i == j)
            {
                if (x[i][j] != 1)
                {
                    not_i = 1;
                }
            }
            else
            {
                if (x[i][j] != 0)
                {
                    not_i = 1;
                }
            }
        }
    }
    if (not_i == 0)
    {
        cout << "identity";
    }
    else
    {
        cout << "not identity";
    }
}
