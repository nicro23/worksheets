#include <iostream>
using namespace std;

int main()
{
    int x[30], tot=0,a,b;
    float avg,ct;
    for(int i = 0;i<30;i++)
    {
        cin>>x[i];
    }
    cin>>a>>b;
    ct = b-a+1;
    while(a<=b)
    {
        tot += x[a];
        a++;
    }
    avg = tot/ct;
    cout<<avg;
}