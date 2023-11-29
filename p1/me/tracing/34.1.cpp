


int main()
{
	int w, k;    int Z = 5;   k = 1;		w = 0;

	for (int i = 1; i < 800; i++)
	{
		if (i <= 2 || i == 11)
		{
			while (w < 1)
			{
				if (k % Z == 0)
				{
					break;
				}

				cout << w << endl;
				cout << k << endl;
				k++;
				w--;
			}
		}
		else
		{
			if (Z < 10)
			{
				k++;
				Z += 2;
			}
			if (i == 12)
			{
				break;
			}
			
		}
	}
}