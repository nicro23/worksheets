#include<iostream>
using namespace std;
void main()
{
	int tv, ac, fz, lmp, bill;
	cout << "enter hours for television: ";
	cin >> tv;
	cout << "enter hours for air conditioner: ";
	cin >> ac;
	cout << "enter hours for freezer: ";
	cin >> fz;
	cout << "enter hours for lamp: ";
	cin >> lmp;
	bill = (tv * 3) + (ac * 13) + (fz * 7) + (lmp);
	cout << "your bill is: " << bill;
}
