#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void TaskSort(vector<vector<int>>& T) {
    sort(T.begin(), T.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });
}

int main(void)
{
    int k = 0;
    cin >> k;
    vector<vector<int>> task(k, vector<int>(2)); // 确保初始化大小
    for (int i = 0; i < k; i++) {
        cin >> task[i][0] >> task[i][1];
    }

    TaskSort(task);

    for(int i = 0; i < k ; i++)
    {
        cout << task[i][0] << task[i][1] << endl;
    }
}