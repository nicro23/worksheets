#include<iostream>
#include<stdio.h>
using namespace std;

struct dc_process
{
	char tag;
	char type;
	int price;
	int month;
	int day;
};

struct dc_shop
{
	char name;
	int num_process;
	dc_process* p;
};

void main()
{
	int i, j, n;
	cin >> n;
	dc_shop* s;
	s = new dc_shop[n];
	for (i = 0; i < n; i++)
	{
		cin >> s[i].name;
		cin >> s[i].num_process;
		s[i].p = new dc_process[s[i].num_process];
		for (j = 0; j < s[i].num_process; j++)
		{
			cin >> s[i].p[j].tag;
			cin >> s[i].p[j].type;
			cin >> s[i].p[j].price;
			cin >> s[i].p[j].month;
			cin >> s[i].p[j].day;
		}

		int sel_shop,month,day,ct = 0;
		cin >> sel_shop;
		cin >> month;
		cin >> day;
		for (j = 0; j < s[sel_shop].num_process; j++)
		{
			if (s[sel_shop].p[j].day == day && s[sel_shop].p[j].month == month)
			{
				ct++;
			}
		}
		cout << ct<<endl;
		int pos, max = -99999, tot = 0;
		cin >> sel_shop;
		for (i = 1; i < 13; i++)
		{
			ct = 0;
			for (j = 0; j < s[sel_shop].num_process; j++)
			{
				if (s[sel_shop].p[j].month == i)
				{
					tot += s[sel_shop].p[j].price;
				}
			}
			if (tot > max)
			{
				max = tot;
				pos = i;
			}
		}
		cout << pos;
		for (i = 0; i < n; i++)
		{
			delete[] s[i].p;
		}
		delete[] s;
	}
}