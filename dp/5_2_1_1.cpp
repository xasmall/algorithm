#include<bits/stdc++.h>
using namespace std;

// hdu 1712 分组背包
const int N = 110;
int dp[N],w[N][N];

int main(){
    int n,m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) return 0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin >> w[i][j];
            }
        
        for(int i=1;i<=n;i++){
            for(int j=m;j>=0;j--){
                for(int k=1;k<=m;k++){
                    if(j>=k){
                        dp[j] = max(dp[j],dp[j-k]+w[i][k]);
                    }
                }
            }
        }
        cout << dp[m] << endl;
    }
}