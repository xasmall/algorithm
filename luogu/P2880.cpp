#include<bits/stdc++.h>

using namespace std;

// ST算法
const int N = 50005;
int dp1[N][22]; // 最小值
int dp2[N][22]; // 最大值
int a[N];
int n;
// 最小的
void work1(){
    for(int i=1;i<=n;i++){
        dp1[i][0] = a[i];
    }
    for(int i=1;(1<<i) <=n ;i++){
        for(int j=1;j + (1<<i) -1<=n;j++){
            dp1[j][i] = min(dp1[j][i-1],dp1[j+ (1<<(i-1))][i-1]);
        }
    }
}
void work2(){
    for(int i=1;i<=n;i++){
        dp2[i][0] = a[i];
    }
    for(int i=1;(1<<i<=n);i++){
        for(int j=1;j+(1<<i) - 1 <=n ;j++){
            dp2[j][i] = max(dp2[j][i-1],dp2[j + (1<<(i-1))][i-1]);
        }
    }
}
int RMQ1(int l ,int r){
    int k = 0;
    while((1<<(k))<=(r-l + 1)) k++;
    k--;
    return min(dp1[l][k],dp1[r-(1<<k) +1][k]);
}
int RMQ2(int l ,int r){
    int k = 0;
    while((1<<(k))<=(r-l + 1)) k++;
    k--;
    // 要保证可以覆盖全部
    return max(dp2[l][k],dp2[r-(1<<k) +1][k]);
}
int main(){
    int q; scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    work1();
    work2();
    while(q-->0){
        int l, r;
        scanf("%d%d",&l,&r);
        printf("%d\n",RMQ2(l,r)-RMQ1(l,r));
    }
    return 0;

}