#include<iostream>
using namespace std;

void main()
{
    int i, n1, n2, ct, diff, diff_prev,cti, ctd, isdec;
    char j;
    j = 'k';
    i = -1;
    cti = 0;
    ctd = 0;
    isdec = 0;
    while(true)
    {   
        cout<<"number? (y/n)"<<endl;
        cin>>j;
        if( j =='n')
        {
            break;
        }
        if(i > 0)
        {
            diff_prev = diff;
        }
        if(i > -1)
        {
            n2 = n1;
        }
        cin>>n1;
        if(i > -1)
        {
            diff = n1 - n2;
        }
        if(i > 0)
        {
            if( diff_prev == diff && diff< 0)
            {
                isdec = 1;
            }
            if( diff_prev == diff && diff > 0 && isdec == 0)
            {
                cti++;
            }
            if( diff_prev == diff && diff < 0 && isdec == 1)
            {
                ctd++;
            }
        }
        i++;
    }
    if( cti == ctd)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

}