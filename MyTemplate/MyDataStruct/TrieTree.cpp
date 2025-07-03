#include <iostream>
#include <string>
using namespace std;
#define il inline
const int N=15e4+200;
const int M=26;
int tree[N][M], pass[N], end[N];
int cnt;

il void build()
{
    cnt=1;
}

il void insert(string word)
{
    int cur=1;
    pass[cur]++;    //现在头节点进行添加
    for(int i=0,path;i<word.size();i++)
    {
        path = word[i]-'a';
        if(tree[cur][path] == 0)    //没有该路径
            tree[cur][path]=++cnt;  //开辟新节点
        cur=tree[cur][path];        //获取下一个节点的编号
        pass[cur]++;
    }
    end[cur]++;
}

il int search(string word)
{
    int cur=1;
    for(int i=0,path;i<word.size();i++)
    {
        path = word[i]-'a';
        cur=tree[cur][path];
        if(!cur) break; //如果出现0节点，说明没有
        if(i==word.size()-1) return end[cur];
    }
    return 0;
}