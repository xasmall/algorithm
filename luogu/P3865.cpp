#include<bits/stdc++.h>
using namespace std;

// ST模板题
const int N = 1e5 + 5;
int a[N];
int f[N][22];
int n;
void work(){
    for(int i=1;i<=n;i++) f[i][0] = a[i];
    for(int i=1;(1<<i)<=n;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            f[j][i] = max(f[j][i-1],f[j + (1<<(i-1))][i-1]);
        }
    }
}
int RMQ(int l,int r){
    int k = 0;
    while((1<<k)<=(r - l + 1)) k++;
    k--;
    return max(f[l][k],f[r -(1<<k) + 1][k]);
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    work();
    while(m-->0){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",RMQ(l,r));
    }
}