#include <iostream>
using namespace std;

void main()
{
    int a, ct =0;
    float tot =0, avg;
    int x[30], y[30];
    for (int i = 0; i < 30; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < 30; i++)
    {
        cin >> y[i];
    }
    cin >> a;
    if (a == 1)
    {
        for (int i = 0; i < 30; i++)
        {
            if (x[i] > 170 && y[i] > 100)
            {
                cout << x[i] << " " << y[i] << endl;
            }
        }
    }
    if (a == 2)
    {
        for (int i = 0; i < 30; i++)
        {
            if (x[i] < 80)
            {
                cout << y[i] << endl;
            }
        }
    }
    if(a == 3)
    {
        for(int i = 0;i<30;i++)
        {
            if(x[i]>100)
            {
                ct++;
                tot += y[i];
            }
        }
        avg = tot/ct;
        cout<<avg;
    }
}