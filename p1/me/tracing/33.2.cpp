


int main()
{
	char x;
	char y = 'k';

	char k = 'a';
	int a = 2;
	x = k;
	while (x != y)
	{		
		x = k;
		for (int i = 0; i<3; i++)
		{
			cout << x << endl;
			x += a;
		}
		while (a < 3)
		{
			a++;
		}
		k++;		
	}
}
