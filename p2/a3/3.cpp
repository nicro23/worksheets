#include<iostream>
#include<stdio.h>
using namespace std;

struct chicken
{
	char gender;
	int age;
	char flu;
};

struct another
{
	int num_chickens;
	chicken* c;
	char city;
};

void main()
{
	int i, j, n;
	another* f;
	cin >> n;
	f = new another[n];
	for (i = 0; i < n; i++)
	{
		cin >> f[i].num_chickens;
		f[i].c = new chicken[f[i].num_chickens];
		for (j = 0; j < f[i].num_chickens; j++)
		{
			cin >> f[i].c[j].gender;
			cin >> f[i].c[j].age;
			cin >> f[i].c[j].flu;
		}
		cin >> f[i].city;
	}
	float ct = 0;
	char sel_city;
	cin >> sel_city;
	for (i = 0; i < n; i++)
	{
		if (f[i].city == sel_city)
		{
			ct++;
		}
	}
	cout << ct<<endl;
	int sel_farm;
	cin >> sel_farm;
	ct = 0;
	for (j = 0; j < f[sel_farm].num_chickens; j++)
	{
		if (f[sel_farm].c[j].flu == 'y')
		{
			ct++;
		}
	}
	float num_disease = ct / (f[sel_farm].num_chickens) * 100;
	cout << num_disease;
	for (i = 0; i < n; i++)
	{
		delete[] f[i].c;
	}
	delete[] f;
}