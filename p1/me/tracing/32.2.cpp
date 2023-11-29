


int main()
{
	char x = 'a';
	char y = 'z';

	int k = 2;

	while (x != y)
	{
		x += k;
		cout << x << endl;
		for (int i = 0; i<3; i++)
		{
			y--;
		}

		cout << y << endl;

		x = y++		+2;
		cout << x++ << endl;
		cout << y++ << endl;
		cout << y++ << endl;

	}
}