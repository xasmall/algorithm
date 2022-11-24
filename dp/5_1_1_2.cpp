#include<bits/stdc++.h>
using namespace std;
// 记忆化搜索
const int N = 1010;
int dp[N][N];
int s[N];
int v[N];
int solve(int i,int j){
    if(dp[i][j]!=0) return dp[i][j];
    if(i==0) return 0;
    int res;
    if(j<v[i]) res = solve(i-1,j);
    else res = max(solve(i-1,j),solve(i-1,j-v[i])+s[i]);
    dp[i][j] = res;
    return res;
}

int main(){
    int t; cin >> t;
    while(t-->0){
        int n,c;
        cin >> n >> c;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) cin >> s[i];
        for(int i=1;i<=n;i++) cin >> v[i];
        cout << solve(n,c) << endl;
    }
    return 0;
}