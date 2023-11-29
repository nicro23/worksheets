


int main()
{
	char x = 'n';
	char y = 'j';

	int k;

	while(x > y)
	{
		
		for (int i=0; i<3; i++)
		{
			y+=2;
			cout<<y;
		}


		for (k=0; k<4; k++)
		{
			y--;
		}
		cout<<endl;
		cout<<"~~~"<<endl;
	}
}