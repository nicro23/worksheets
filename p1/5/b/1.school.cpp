#include<iostream>
using namespace std;

void main()
{
    int ct, s, c, ns, h1n1, flu, max, pos, ct, toth1n1, ss;
    ct = 0;
    cin>>s;
    for(int i=1;i<=s;i++)
    {
        max= -99999;
        ss= 0;
        toth1n1 = 0;
        cin>>c;
        for(int j=1;j<=c;j++)
        {
            cin>>ns>>h1n1>>flu;
            if(flu>max)
            {
                max = flu;
                pos = j;
            }
            ss+= ns;
            toth1n1+= h1n1;
        }
        if(toth1n1>(ss*0.05))
        {
            ct++;
        }
        cout<<"in school "<<i<<" the class with the most flu cases was: "<<pos<<endl;
        

    }
    cout<<"schools to be closed "<<ct;
}