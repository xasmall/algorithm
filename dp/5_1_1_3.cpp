#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int dp[N],w[N],v[N];
int main(){
    int t; cin >> t;
    while(t-->0){
        int n,c; cin >> n >> c;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) cin >> w[i];
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=n;i++){
            for(int j=c;j>=v[i];j--){
                dp[j] = max(dp[j],dp[j-v[i]] + w[i]);
            }
        }
        cout << dp[c] << endl;
    }
    return 0;
}
