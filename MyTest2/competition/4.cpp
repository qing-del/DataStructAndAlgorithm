#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Task_Split(vector<vector<int>>& T, int& day, int& index, vector<int>& D_T, int k);
long long ExtendAdd(const int& n, const vector<int>& D_T);

// 区分一天的任务出来
void Task_Split(vector<vector<int>>& T, int& day, int& index, vector<int>& D_T, int k) {
    D_T.clear();
    for (int i = index; i < k; i++) {
        if (T[i][0] == day) {
            D_T.push_back(T[i][1]);
        } else if (T[i][0] > day) {
            index = i;
            return;
        }
    }
    index = k; //所有任务都搞定了
}

long long ExtendAdd(const int& n, const vector<int>& D_T) {
    int num = 0, count = 0, xu = 0; // 是额外加点数，练剑次数，第xu个任务
    long long p = 0;
    while(count < n && xu < D_T.size())
    {
        if (count >= D_T[xu])
        {
            xu++;
            num++;
        } else
        {
            p += num;
            count++;
        }
        
    }

    while(count < n){
        p += num;
        count++;
    }

    return p;
}

int main() {
    int day = 1, T_index = 0;
    int n, m, k; // 一共出手n次，练习m天，有k个任务
    cin >> n >> m >> k;

    // 定义数组储存数据（任务）
    vector<vector<int>> task(k, vector<int>(2)); // 确保初始化大小
    for (int i = 0; i < k; i++) {
        cin >> task[i][0] >> task[i][1];
    }

    // 创建一个数组用于储存每天的任务
    vector<int> D_T;

    // 创建一个数组，储存每天出手的熟练度
    vector<long long> p(m);
    int pi = 0;

    while (day <= m) {
        Task_Split(task, day, T_index, D_T, k);
        p[pi] = ExtendAdd(n, D_T);
        pi++;
        day++;
    }

    // 排序并给出最大值
    int max = p[0];
    for(int i = 0; i < m; i++)
    {
        max = max > p[i] ? max : p[i];
    }
    cout << max << endl; // 获取最后一个元素，即最大值

    return 0;
}
