#include <iostream>
using namespace std;

int n, m;
int arr1[150010], arr2[40010];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	for (int i = 0; i < m; i++)
		cin >> arr2[i];
	int count = 0;
	for (int i = 0; i < n - 2; i++)
	{
        bool go = 1;
		for (int j = 0; j < m; j++)
		{
			if (arr1[i + j] < arr2[j])
            {
                go =0;
                break;
            }
		}
        if(go)count++;
	}
	cout << count << endl;
	return 0;
}