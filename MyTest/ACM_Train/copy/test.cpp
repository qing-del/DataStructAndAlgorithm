#include<stdio.h>
int m[2001],num;
int n[1000000];
int main()
{
    int R=-1,L=0,N,M,t,i=0,ansL,ansR;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
    scanf("%d",n+i);
    i=0;
    while(num!=M)
    {
        if(m[n[i]]==0)num++;
        m[n[i]]++;
        R++;
        i++;
    }
    while(m[n[L]]>1)
        m[n[L++]]--;
    ansL=L;ansR=R;
    while(i<N)
    {
        m[n[i]]++;
        R++;
        i++;
        while(m[n[L]]>1)
            m[n[L++]]--;
        if(ansR-ansL>R-L)
        {
            ansR=R;
            ansL=L;
        }
    }
    printf("%d %d",ansL+1,ansR+1);
}
