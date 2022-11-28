#include<bits/stdc++.h>
using namespace std;

int n, dp[1<<20][21];
int dist[21][21];
//状态压缩dp

int main(){
    memset(dp,0x3f,sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> dist[i][j];
    
    dp[1][0] = 0;
    for(int S=1;S<(1<<n);S++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(S>>j&1 && (S^(1<<j)>>k&1)){
                    dp[S][j] = min(dp[S^(1<<j)][k],dist[k][j]);
                }
            }
        }
    }
    cout << dp[1<<n - 1][n-1] << endl;
    // 终点是n-1，且集合中包含所有的点
    return 0;
}