


int main()
{
	char x;	char y = 'm';	char k = 'm';
	x = k;
	int a = 3;		int i = 0;		int b;
	while (x == y)
	{
		b = 0;
		for ( ; i < a ;  i++)
		{
			cout << x << " , ";
			x++;
			b = 1;
			break;
		}

		if (!b)
		{
			y++;
		}
		cout  << x << " >> " << y << endl;


		if (y > x)
		{
			break;
		}
		else
		{
			y++;
		}

		i += 2;
	}
}
