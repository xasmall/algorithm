#include<bits/stdc++.h>
using namespace std;
int n;
int dp[60];
int main(){
    while(scanf("%d",&n),n){
        memset(dp,0,sizeof(dp));
        dp[1] = 0; dp[2] = 1;
        for(int i=3;i<=n;i++){
            dp[i] += i-3>=1?dp[i-3] : 0;
            dp[i] += dp[i-1] + 1;
        }
        cout << dp[n]+1 << endl;
    }
}