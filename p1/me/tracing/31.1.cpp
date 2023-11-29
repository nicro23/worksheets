


int main()
{
	int v = 0;
	int Z = 30;

	for ( int    i = 0 ;    i < 4  ;      )
	{
		cout<< i <<endl;
		
		for (int  k = 0 ;  k < Z ;    k++)
		{
			cout<< k <<endl;

			for(int w=0; w<i; w++ )
			{
				v = v + 20;
				cout<<v<<endl; 
			}

			i++;
			break;
		}

		cout<<"~~~"<<endl;
	}
}