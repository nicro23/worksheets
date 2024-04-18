#include<iostream>
#include<stdio.h>
using namespace std;

struct mail
{
	char name_send;
	int date;
	int day;
	int month;
	int year;
	int risk;
	char msg;
	char name_dest;
};

struct inbox
{
	int num_mails;
	mail* m;
};

void main()
{
	int i, j, n;
	inbox* in;
	cin >> n;
	in = new inbox[n];
	for (i = 0; i < n; i++)
	{
		cin >> in[i].num_mails;
		in[i].m = new mail[in[i].num_mails];
		for (j = 0; j < in[i].num_mails; j++)
		{
			cin >> in[i].m[j].name_send;
			cin >> in[i].m[j].day;
			cin >> in[i].m[j].month;
			cin >> in[i].m[j].year;
			cin >> in[i].m[j].msg;
			cin >> in[i].m[j].risk;
			cin >> in[i].m[j].name_dest;
		}
	}
	int min_range, max_range;
	cin >> min_range >> max_range;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < in[i].num_mails; j++)
		{
			if (in[i].m[j].risk > min_range && in[i].m[j].risk < max_range)
			{
				cout << in[i].m[j].msg << endl;
			}
		}
	}
	int sel_inbox, ct = 0;
	cin >> sel_inbox;
	for (j = 0; j < in[sel_inbox].num_mails; j++)
	{
		if (in[sel_inbox].m[j].risk > 50)
		{
			ct++;
		}
	}
	cout << ct;
	for (i = 0; i < n; i++)
	{
		delete[] in[i].m;
	}
	delete[] in;

}
