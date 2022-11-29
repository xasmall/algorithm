#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,cnt,MAX;
ll dp[20][1000][400];
int can[1000],num[2000];
// 状态压缩dp 洛谷 P1896

int getsum(int x){
    int res = 0;
    while(x){
        res += (x&1);
        x >>= 1;
    }
    return num[cnt]=res;
}

int main(){
    ll ans = 0;
    cin >> n >> m;
    MAX = (1<<n) - 1;
    for(int i=0;i<=MAX;i++) if(!(i&(i<<1))){
        can[++cnt] = i;
        dp[1][cnt][getsum(i)] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=cnt;j++){
            int x = can[j];
            for(int k=1;k<=cnt;k++){
                int y = can[k];
                if(x&y||x&(y<<1)||x&(y>>1)) continue;
                for(int l=0;l<=m;l++) dp[i][j][num[j]+l] += dp[i-1][k][l]; 
            }
        }
    }
    for(int i=1;i<=cnt;i++) ans += dp[n][i][m];
    cout << ans <<endl;
    return 0;
}