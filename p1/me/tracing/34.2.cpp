


int main()
{
	char x;
	char y = 'm';
	char k = 'a';
	int a = 1;
	int t = 1;
	x = k;
	while (x != y)
	{
		x = k;
		for (int i = 0; i<3; i++)
		{
			cout << x << " , ";
		}
		cout << endl;
		while (a < 3*t)
		{
			a += a;
		}

		k+=a;
		t++;
	}
}
