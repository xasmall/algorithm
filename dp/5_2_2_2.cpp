#include<bits/stdc++.h>
using namespace std;

// luogu 2347 多重背包

const int N = 1010;
int dp[N];
int t[6] = {1,2,3,5,10,20};
int m[6];
int cnt = 0;
int w[N];

int main(){
    int a[6];
    for(int i=0;i<6;i++) cin >> a[i];
    for(int i=0;i<6;i++){
        for(int j=1;j<=a[i];j<<=1){
            a[i] -= j;
            w[++cnt] = j * t[i];
        }
        if(a[i]){
            w[++cnt] = a[i] * t[i];
        }
    }
    for(int i=1;i<=cnt;i++){
        for(int j=N-1;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]] + w[i]);
        }
    }
    int ans = 0;
    for(int i=1;i<N;i++){
        if(dp[i] == i) ans ++;
    }
    cout << "Total=" << ans << endl;
    
}
