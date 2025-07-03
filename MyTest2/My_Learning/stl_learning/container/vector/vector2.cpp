#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    cout << arr.size() << endl;

    arr.pop_back();
    arr.pop_back();

    for (auto &ele : arr)
    {
        cout << ele << endl;
    }

    system("pause");
    
}