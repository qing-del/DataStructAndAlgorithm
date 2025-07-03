#include <bits/stdc++.h>
using namespace std;
#define ms(x,n) memset(x,n,sizeof(x))
#define il inline
#define rg register
#define ll long long
#define ull unsigned ll
#define uint unsigned int
int a,b,c,d;

il double f(double x){
    return a*x*x*x+b*x*x+c*x+d;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b>>c>>d;

    set<double> ans;
    for(int i=-100;i<100&&ans.size()<3;i++)
    {
        double l=i,r=i+1;
        double f1=f(l),f2=f(r);
        if(f1*f2>0) 
            continue;
        
        bool flag=0;
        while(r-l>=0.0001)
        {
            double mid=(l+r)/2;
            if(!f1){
                ans.insert(l);  
                break;
            }

            double res=f(l)*f(r);
            if(res<0)
                l=mid;
            else if(res>0)
                r=mid;
            else
            {
                if(f(l)==0)
                    ans.insert(l);
                else
                    ans.insert(r);
                flag=1;
                break;
            }
        }

        if(!flag)
            ans.insert(r);
    }

    for(auto it=ans.begin();it!=ans.end();it++)
        cout<<fixed<<setprecision(2)<<*it<<"\n";

    return 0;
}
