#include<iostream>
using namespace std;
void main()
{
    int n, nc, rc, pos_max, posd_min, posh_min;
cin>>n;
int min = 999999;
for(int i=1; i<=n;i++)
{
    //determin which day records the maximum usage ratio (in each hall not in all halls)
    int max= -99999;
    cin>>nc;
    for(int j=1;j<=nc;j++)
    {
        cin>>rc;
        if((rc/nc) > max)
        {
            max = (rc/nc);
            pos_max = j;
        }
        if((rc/nc) < min)
        {
            min =(rc/nc);
            posd_min = j;
            posh_min = i;
        }
        cout<<"most crowded day was:"<<pos_max<<endl;
    }
    
}
cout<<"day with lowest ratio was:"<<posd_min<<" in hall "<<posh_min;
}