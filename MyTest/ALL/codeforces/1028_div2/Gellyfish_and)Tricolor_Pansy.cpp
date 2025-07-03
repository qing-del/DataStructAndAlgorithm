//来自codeforces round-1028 div.2 
//链接：https://codeforces.com/contest/2116/problem/A

#include <bits/stdc++.h>
using namespace std;
#define il inline
const string player1 = "Gellyfish", player2="Flower";
int a,b,c,d;

il int Min(int a, int b) {return a<b?a:b;}

il void solve()
{
    cin>>a>>b>>c>>d;
    int min1 = Min(a,c),min2=Min(b,d);
    if(min1>=min2) cout<<player1<<"\n";
    else cout<<player2<<"\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}