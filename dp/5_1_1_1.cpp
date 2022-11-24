#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int dp[N][N];
int s[N];
int v[N];
// hdu 2602
int main(){
    int t; cin >> t;
    int n,c;
    while(t-->0){
        cin >> n >> c;
        for(int i=1;i<=n;i++) cin >> s[i];
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=n;i++){
            for(int j=0;j<=c;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=v[i]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-v[i]] + s[i]);
                }
            }
        }
        cout << dp[n][c] << endl;
    }
}