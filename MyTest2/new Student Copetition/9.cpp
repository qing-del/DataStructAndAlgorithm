#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> square(10 , vector<int>(10 , 1));

int up(int n, int t);
void Build(int size, int x, int y);
void Print(int n);


int main()
{
    int N;
    cin >> N;
    int size = up(2, N);

    Build(size, 0, 0);

    Print(size);

}

int up(int n, int t)
{
    if(t == 1 || t == 0)
    {
        return n;
    }
    return n * up(n, t - 1);
}

void Build(int size, int x, int y)
{
    int newSize = size / 2;
    for (int i = y; i < newSize + y; i++)
    {
        for (int j = x; j < newSize + x; j++)
        {
            square[i][j] = 0;
        }
    }
    
    if (newSize == 1)
    {
        return;
    }
    
    Build(newSize, x + newSize, y);
    Build(newSize, x, y + newSize);
    Build(newSize, x + newSize, y + newSize);
}

void Print(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << square[i][j];
            if(j != n - 1) cout << " ";
        }
        cout << endl;
    }
}