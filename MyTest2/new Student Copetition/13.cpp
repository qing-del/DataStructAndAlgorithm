#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin  >> N;

    vector<vector<int>> map(N,vector(N,0));

    int x,y;

    x = N / 2 , y = 0;

    for (int i = 1; i <= N * N; ++i)
    {
        map[y][x] = i;

        int px = x;
        int py = y;

        y--;
        x++;

        if(x >= N)
        {
            x = 0;
        }

        if(y < 0)
        {
            y = N - 1;
        }

        if (map[y][x] != 0)
        {
            x = px;
            y = py - 1;
            if(y >= N) y = 0;
        }
    }
    
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            cout << map[i][j];
            if (j != N - 1)
            {
                cout << " ";
            }
            
        }
        cout << endl;
    }

    return 0;
}