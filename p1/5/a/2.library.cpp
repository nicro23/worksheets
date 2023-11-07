#include<iostream>
using namespace std;

void main()
{
    int neb, nmb, ns, teb, tmb, ctm, cts;
    ctm = 0;
    cts = 0;
    for(int i = 1; i<=30; i++)
    {
        cin>>neb>>nmb>>ns;
        for(int j=1; j<=ns; j++)
        {
            cin>>teb>>tmb;
            //what if the user inputed 10 math books while there is less than 10 left
            neb = neb - teb;
            nmb = nmb - tmb;
            if(tmb >= 10 && nmb >= 0)
            {
                ctm++;
            }
        }
        if(neb < 0)
            {
                cts++;
            }
    }
    cout<<"count of students who took more than 10 math books: ";
    cout<<ctm<<endl;
    cout<<"count of days without enough english books: ";
    cout<<cts; 
}