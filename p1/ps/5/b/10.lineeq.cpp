#include<iostream>
using namespace std;

void main()
{   
    int nl, i;
    float stpx, stpy, edpx, edpy, l, tot, ct_avg, avg, max, min;
    cin>>nl;
    for(i=1;i<=nl;i++)
    {
        cin>>stpx>>stpy>>edpx>>edpy;
        l = (edpx - stpx)*(edpx - stpx) + (edpy - edpx)*(edpy - edpx);
        tot+= l;
        ct_avg++;
        if(l > max)
        {
            max = l;
        }
        if(l < min)
        {
            min = l;
        }
    }
    avg = tot/ct_avg;
    cout<<max<<endl<<min<<endl<<avg;
}