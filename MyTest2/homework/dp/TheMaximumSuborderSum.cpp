#include <iostream>
using namespace std;
const int N=2e5+10;
int n,a[N],ans,sum;

int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

int main()
{
    n=read();
    for(int i=0;i<n;i++) a[i]=read();
    
    return 0;
}