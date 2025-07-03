#include <iostream>
using namespace std;

int N,K;
int arr[8];
int sequence[8];

void Creat(int n, int sum);
void Print();

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    Creat(0, 0);

    system("pasue");
    
    return 0;
}

void Creat(int n, int sum)
{
    if (n == N)
    {
        if (sum % K == 0)
        {
            Print();
        }
        return;
    }

    for (int i = 1; i <= arr[n]; i++)
    {
        sequence[n] = i;
        Creat(n + 1, sum + i);
    }
    
}

void Print()
{
    for (int i = 0; i < N; i++)
    {
        cout << sequence[i] << " ";
    }
    cout << endl;
}