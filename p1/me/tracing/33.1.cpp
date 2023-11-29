


int main()
{
	int w , k;
        int Z = 2;
        k=2;

	for (   int i = 1 ;    i < 800   ;  )
	{
		for ( w = 0 ; w < 1 ; w-- )
		{
			if (k % 5 == 0)
			{		
				break;
			}
			
			cout << w << endl;
			cout << k << endl;
k++;

		}

		for ( ; i < Z ; )
		{
			i  = i * 100;
cout << i << endl;
		}
		Z = 200;
k++;
	}
}