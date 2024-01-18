#include<iostream>
using namespace std;

void main()
{
    float ds, prc, n, c, s;
    cin>>ds>>prc;
    n = ds*prc;
    c = n*1.12;
    s = n*0.25;
    cout<<"normal: "<<n<<endl;
    cout<<"comfort: "<<c<<endl;
    cout<<"shuttle: "<<s;
}