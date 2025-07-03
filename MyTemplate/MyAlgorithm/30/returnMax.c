#include <stdio.h>
int n,a,ans;
//反转0与1
bool filp(bool x){
    return x^1;
}
//获取x的符号位 如果是正数就返回1 如果是负数就返回0
bool sign(int x){
    return filp(x>>31);
}
//无比较获得最大值(max)
int getMax(int a, int b){
    int c=a-b;
    bool sa=sign(a);
    bool sb=sign(b);
    bool sc=sign(c);
    //a与b的符号是否不同
    bool diffAB=sa^sb;
    //a与b的符号是否相同
    bool sameAB=filp(diffAB);
    //返回a的条件为 ab符号不同且a是正数 or ab符号相同 c是正数
    bool returnA=(sa & diffAB) | (sc & sameAB);
    //获取b的返回条件
    bool returnB=filp(returnA);

    return a*returnA + b*returnB;
}