#include<iostream>
using namespace std;
void main()
{
	int y1, m1, d1;
	int y2, m2, d2;
	int did;
	cout << "enter first date (format dd/mm/yyyy)" << endl;
	cin >> d1;
	cin >> m1;
	cin >> y1;
	cout << "enter second date (format dd/mm/yyyy)" << endl;
	cin >> d2;
	cin >> m2;
	cin >> y2;
	did = (y2 * 365 + m2 * 30 + d2) - (y1 * 365 + m1 * 30 + d1);
	cout << "difference in days= " << did;

}