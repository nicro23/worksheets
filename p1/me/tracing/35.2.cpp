


int main()
{
	char x;
	char y = 'm';
	char k = 'm';
	x = k;
	int a= 3;
	while (x == y)
	{		
		for (int i = 0; i<a; i++)
		{
			cout << x << " , ";
			x++;
		}
		cout << endl;
		while (y < x)
		{
			cout<< y << " , ";
			y++;
			x--;
		}
		cout<<y<<endl;
		cout<<x++<<endl;
		a--;
	}
}
