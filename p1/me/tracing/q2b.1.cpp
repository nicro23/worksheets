


int main()
{
	int i,w;
	i = 0;
	for (int k=30; k>0; k++)
	{	
		for( w = 0 ; w < 2; w++)
		{			
			cout<<k<<endl;
			k -= 10;
		}
		k -= w;
		cout<<k<<endl;
	}
}
