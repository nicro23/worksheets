#include<iostream>
using namespace std;

void main()
{
    int n1, n2, a, b, c, eq1, eq2;
    cin>>n1>>n2;
    if ((n1/10) == (n2/10))
    {
        a = n1/10;
        b = n1%10;
        c = n2%10;
        eq1 = 100*a*(a+1);
        eq2 = b*c;
        cout<<eq1<<endl<<eq2;
    }
    else
    {
        cout<<"error";
    }
}