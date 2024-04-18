#include <iostream>
#include<stdio.h>
using namespace std;

struct hole
{
	int type;
	int n_nuts;
};

struct sqrl
{
	char name;
	int num;
	hole* h;
};

void main()
{
	int n;
	sqrl* s;
	s = new sqrl[n];

}