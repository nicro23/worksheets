


int main()
{
	int w;
	for (   int i = 0 ;    i < 800   ;  )
	{
		for ( w = 0 ; w < 50 ; w++ )
		{
			if (i < 0 )
			{
				i = w;
				break;
			}

			w = w  * i;
			i += 10;

			if ( i >= 100 )
			{
				i = w - 1;
				break;
			}
			cout << w << endl;
		}

		if (i == 0)
		{
			break;
		}
		cout << i << endl;
		cout << "~~~" << endl;
	}
}