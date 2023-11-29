


int main()
{
	int w, k;    int Z = 5;   
	k = 1;
	for (int a = 1; a <= 2; a++)
	{
		for (int i = 1; i < 3; i++)
		{
			for (w=Z; w>=k; w-- )
			{
				cout<<w<<endl;
			}
			Z = Z - 2;
			for (  ; k<Z ; k++ )
			{
				cout<<k<<endl;
			}
			Z = Z + 2;
			cout<<"=======================\n";
		}
		Z = Z * 2; 
		k = k * 2;
	}
}
