#include<iostream>
using namespace std;

int main()
{
    int n, r, tot, diff, diff_prev, big_diff, big_diff_prev, bigger_diff, v1, v2;
    r = 1;
    tot = 0;
    cin>>n;
    cin>>v2;
    for(int i= 1; i<n;i++)
    {
            v1 = v2;
        cin>>v2;
            r*= 10;
            diff = (v1%r / (r/10)) - (v2%(r*10) / r);
            tot += diff;
    }
    cout<<tot;
}