#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateLIS(const vector<int>& arr) {
    vector<int> lis;
    for (int num : arr) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }
    return lis.size();
}

int main() {
    int length;
    cin >> length;
    
    vector<int> arr(length);
    for (int i = 0; i < length; ++i) {
        cin >> arr[i];
    }

    int maxPromote = 0;

    for (int i = 0; i < length; ++i) {
        vector<int> newArr;
        for (int j = 0; j < length; ++j) {
            if (j != i) {
                newArr.push_back(arr[j]);
            }
        }

        int count = calculateLIS(newArr);
        maxPromote = max(maxPromote, count);
    }

    cout << maxPromote << endl;

    return 0;
}
