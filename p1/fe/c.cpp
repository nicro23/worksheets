#include<iostream>
#include<stdio.h>
using namespace std;

void fun(char x[])
{
	int z,i,j,k,l,pos,sz,sz_f,sz_m,sz_l,ctl = 0, flg = 0;
	for (i = 0; x[i] != '\0'; i++)
	{
		ctl++;
		if (x[i] == ' ')
		{
			if (flg == 0)
			{
				sz_f = ctl - 1;
				flg = 1;
			}
			sz_m = ctl - 1;
			pos = i - sz_m;
			ctl = 0;
		}
	}
	sz_l = ctl;
	j = sz_f / 2;
	sz = i - 1;
	for (k = 0; k < sz_m / 2; k++)
	{
		z = x[pos];
		for (l = pos; l > j; l--)
		{
			x[l] = x[l - 1];
		}
		x[j] = z;
		j++; pos++;
	}
	for (k = 0; k < sz_m / 2; k++)
	{
		z = x[pos];
		for (l = pos; l < sz - (sz_l / 2); l++)
		{
			x[l] = x[l + 1];
		}
		x[l] = z;
	}
	for (j = pos; j < sz + 1;j++)
	{
		x[j] = x[j + 1];
	}
	
}

void main()
{
	char x[200];
	gets_s(x);
	fun(x);
	cout << x;
}
