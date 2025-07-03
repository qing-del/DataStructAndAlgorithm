#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "I love Luogu!" << endl;
        break;
    case 2:
        cout << 2 + 4 << " " << 10 - 2 - 4 << endl;
        break;
    case 3:
        cout << 3 << endl;
        cout << 12 << endl;
        cout << 2 << endl;
        break;
    case 4:
        cout << fixed << setprecision(3) << (double)500.0 / 3 << endl;
        break;
    case 5:
        cout << (260 + 220) / (12 + 20) << endl;
        break;
    case 6:
        cout << sqrt(6 * 6 + 9 * 9) << endl;
        break;
    case 7:
        cout << 100 + 10 << endl;
        cout << 110 - 20 << endl;
        cout << 0 << endl;
        break;
    case 8:
        cout << (5.0 * 2.0 * 3.141593) << endl;
        cout << (5.0 * 5.0 * 3.141593) << endl;
        cout << 4.0 / 3 * 3.141593 * 125<< endl;
        break;
    case 9:
        cout << (((1+1)*2+1)*2+1)*2 << endl;
        break;
    case 10:                        //不会做
        cout << 9 << endl;
        break;
    case 11:
        cout << (double)(100.0 / 3) << endl;
        break;
    case 12:
        cout << (int)('M' - 'A' + 1) << endl;
        cout << (char)('A' + 17) << endl;
        break;
    case 13:
    {
        double pi = 3.141593;
        double sum = 4.0 / 3 * (4 * 4 * 4 + 10 * 10 * 10) * pi;
		cout << (int)pow(sum, 1.0 / 3);
        break;
    }
    case 14:
    {
    int a[2];
	int j = 0;
	for (int i = 0; i < 100; i++){
		if ((110 - i) * (10 + i) == 3500)	a[j++] = 110 - i;
	}
	if (a[0] >= a[1])	cout << a[1];
	else	cout << a[0];
    }
        break;
    default:
        break;
    }
    return 0;
}