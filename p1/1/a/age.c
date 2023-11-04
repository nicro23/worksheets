#include <iostream.h>
using namespace std;
void main ()
{
    int age;
    int age_months;
    int age_days;
    cin >> age;
    age_months = age*12;
    age_days = age_months*30;
    cout << age_months;
    cout << age_days;
}