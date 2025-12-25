// 0-1背包问题 - 回溯算法求解
#include <bits/stdc++.h>
using namespace std;
#define il inline
#define endl '\n'
#define ms(x, n) memset(x, n, sizeof(x))
const int N = 100;

int n, capacity;
int weights[N], values[N];
int bestValue; // 最优价值
vector<int> bestSolution; // 最优解
bool currentSolution[N]; // 当前解

il int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

// 简单上界函数：剩余物品全部装入（松弛条件）
int simpleBound(int i, int currentWeight, int currentValue)
{
    int remainingValue = 0;
    for(int j = i; j <= n; j++)
    {
        if(currentWeight + weights[j] <= capacity)
        {
            currentWeight += weights[j];
            remainingValue += values[j];
        }
    }
    return currentValue + remainingValue;
}

// 增强上界函数：分数背包贪心上界
int enhancedBound(int i, int currentWeight, int currentValue)
{
    int remainingCapacity = capacity - currentWeight;
    int remainingValue = 0;
    
    // 按单位价值排序的剩余物品（这里需要预处理，为了简化直接遍历）
    for(int j = i; j <= n && remainingCapacity > 0; j++)
    {
        if(weights[j] <= remainingCapacity)
        {
            remainingValue += values[j];
            remainingCapacity -= weights[j];
        }
        else
        {
            remainingValue += values[j] * remainingCapacity / weights[j];
            break;
        }
    }
    
    return currentValue + remainingValue;
}

// 版本1：简单上界 cp + rp < bestp
void backtrackSimple(int i, int currentWeight, int currentValue)
{
    if(i > n)
    {
        if(currentValue > bestValue)
        {
            bestValue = currentValue;
            bestSolution.clear();
            for(int j = 1; j <= n; j++)
                if(currentSolution[j])
                    bestSolution.push_back(j);
        }
        return;
    }
    
    // 检查上界条件
    if(simpleBound(i, currentWeight, currentValue) <= bestValue)
        return;
    
    // 选择物品i
    if(currentWeight + weights[i] <= capacity)
    {
        currentSolution[i] = true;
        backtrackSimple(i + 1, currentWeight + weights[i], currentValue + values[i]);
        currentSolution[i] = false;
    }
    
    // 不选择物品i
    backtrackSimple(i + 1, currentWeight, currentValue);
}

// 版本2：增强上界 cp + brp > bestp
void backtrackEnhanced(int i, int currentWeight, int currentValue)
{
    if(i > n)
    {
        if(currentValue > bestValue)
        {
            bestValue = currentValue;
            bestSolution.clear();
            for(int j = 1; j <= n; j++)
                if(currentSolution[j])
                    bestSolution.push_back(j);
        }
        return;
    }
    
    // 检查增强上界条件
    if(enhancedBound(i, currentWeight, currentValue) <= bestValue)
        return;
    
    // 选择物品i
    if(currentWeight + weights[i] <= capacity)
    {
        currentSolution[i] = true;
        backtrackEnhanced(i + 1, currentWeight + weights[i], currentValue + values[i]);
        currentSolution[i] = false;
    }
    
    // 不选择物品i
    backtrackEnhanced(i + 1, currentWeight, currentValue);
}

int main()
{
    cout << "输入物品数量n和背包容量: ";
    n = read();
    capacity = read();
    
    cout << "输入每个物品的重量和价值:" << endl;
    for(int i = 1; i <= n; i++)
    {
        weights[i] = read();
        values[i] = read();
    }
    
    // 按单位价值排序（增强上界需要）
    vector<pair<double, int>> items;
    for(int i = 1; i <= n; i++)
        items.push_back({(double)values[i] / weights[i], i});
    
    sort(items.rbegin(), items.rend()); // 降序排列
    
    vector<int> sortedWeights(n+1), sortedValues(n+1);
    for(int i = 0; i < n; i++)
    {
        sortedWeights[i+1] = weights[items[i].second];
        sortedValues[i+1] = values[items[i].second];
    }
    
    // 使用排序后的数据
    for(int i = 1; i <= n; i++)
    {
        weights[i] = sortedWeights[i];
        values[i] = sortedValues[i];
    }
    
    // 测试简单上界版本
    cout << "=== 简单上界版本 ===" << endl;
    bestValue = 0;
    bestSolution.clear();
    ms(currentSolution, 0);
    backtrackSimple(1, 0, 0);
    
    cout << "最优价值: " << bestValue << endl;
    cout << "选择的物品: ";
    for(int item : bestSolution)
        cout << item << " ";
    cout << endl;
    
    // 测试增强上界版本
    cout << "=== 增强上界版本 ===" << endl;
    bestValue = 0;
    bestSolution.clear();
    ms(currentSolution, 0);
    backtrackEnhanced(1, 0, 0);
    
    cout << "最优价值: " << bestValue << endl;
    cout << "选择的物品: ";
    for(int item : bestSolution)
        cout << item << " ";
    cout << endl;
    
    return 0;
}