#include<iostream>
using namespace std;

int main()
{
    string x,e{"HELLO"},s{"HOLA "},g{"HALLO"},f{"BONJOUR"},i{"CIAO"},r{"ZDRAVSTVUJTE"},l{"#"};
    for(int j=1; ;j++)
    {
        cin>>x;
        if(x == l)
        {
            break;
        }
        else if(x == e)
        {
            printf("Case %i: ENGLISH\n", i);
        }
        else if(x == s)
        {
            printf("Case %i: SPANISH\n", i);
        }
        else if(x == g)
        {
            printf("Case %i: GERMAN\n", i);
        }
        else if(x == f)
        {
            printf("Case %i: FRENCH\n", i);
        }
        else if(x == i)
        {
            printf("Case %i: ITALIAN\n", i);
        }
        else if(x == r)
        {
            printf("Case %i: RUSSIAN\n", i);
        }
        else
        {
            printf("Case %i: UNKNOWN\n", i);
        }
    }
}