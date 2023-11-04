#include <iostream>

void main()
{
    int n1, n2, n3, n4, ct, tot;
    float avg;
    cin>>n1>>n2>>n3>>n4;
    if(!n1%2)
    {
        tot+= n1;
        ct++;
    }
    if(!n2%2)
    {
        tot+= n2;
        ct++;
    }
    if(!n3%2)
    {
        tot+= n3;
        ct++;
    }
    if(!n4%2)
    {
        tot+= n4;
        ct++;
    }
    avg= tot/ct;
    cout<<avg;
}