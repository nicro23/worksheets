#include<iostream>
#include<stdio.h>
using namespace std;

struct building
{
	char type;
	int dur;
};

struct city
{
	char name;
	int num_build;
	building* b;
};

void main()
{
	int i, j, n;
	city* c;
	cin >> n;
	c = new city[n];
	for (i = 0; i < n; i++)
	{
		cin >> c[i].name;
		cin >> c[i].num_build;
		c[i].b = new building[c[i].num_build];
		for (j = 0; j < c[i].num_build; j++)
		{
			cin >> c[i].b[j].type;
			cin >> c[i].b[j].dur;
		}
	}
	int sel_city, ct = 0;
	cin >> sel_city;
	for (j = 0; j < c[sel_city].num_build; j++)
	{
		if (c[sel_city].b[j].dur > 0)
		{
			ct++;
		}
	}
	cout << (ct / (c[sel_city].num_build)) << endl;

	int max = -9999;
	char type;
	cin >> sel_city;
	for (j = 0; j < c[sel_city].num_build; j++)
	{
		if (c[sel_city].b[j].dur > max)
		{
			max = c[sel_city].b[j].dur;
			type = c[sel_city].b[j].type;
		}
	}
	cout << type << endl;

	for (i = 0; i < n; i++)
	{
		delete[] c[i].b;
	}
	delete[] c;
}