#include<iostream>
using namespace std;

void main()
{
    int x[20][15];
    int i, j, min=9999, max=-9999, s_min, s_max;
    float tot, avg;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 15; j++)
        {
            cin >> x[i][j];
        }
    }
    for (i = 0; i < 20; i++)
    {
        tot = 0;
        for (j = 0; j < 15; j++)
        {
            tot += x[i][j];
        }
        avg = tot / 15;
        cout<<"avg absents of student "<<i<<": "<<avg<<endl;
        if (tot > max)
        {
            max = tot;
            s_max = i;
        }
        if (tot < min)
        {
            min = tot;
            s_min = i;
        }
    }
    cout << "student with max absents: " << s_max<<endl;
    cout << "student with min absents: " << s_min << endl;
}
