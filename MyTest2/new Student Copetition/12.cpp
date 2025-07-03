#include <iostream>
#include <vector>
using namespace std;

vector<int> member;

void one(int n);
void two(int n);


int main()
{
    int n, m;

    cin >> n >> m;
    
    member.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> member[i];
    }

    for(int i = 0; i < m; i++)
    {
        int do_;
        cin >> do_;

        if (do_ == 1)
        {
            one(n);
        } else if (do_ == 2)
        {
            two(n);
        }
        
    }
    
    return 0;
}

void one(int n)
{
    int l, r, k;
    cin >> l >> r >> k;
    for (int i = 0; i < n; i++)
    {
        if (member[i] >= l && member[i] <= r)
        {
            member[i] += k;
        }
        
    }        
}

void two(int n)
{
    int l, r, sum;
    cin >> l >> r;
    for(int i = 0; i < n; i++)
    {
        if (member[i] >= l && member[i] <= r)
        {
            sum += member[i];
        }
    }
    cout << sum << endl;
}