#include<bits/stdc++.h>
using namespace std;
#define ll long long 

// luogu 2602 数位dp
const int N = 15;
ll ten[N],dp[N];
ll cnta[N],cntb[N];
int num[N];

void init(){
    ten[0] = 1;
    for(int i=1;i<=N;i++){
        dp[i] = 1LL * i * ten[i-1];
        ten[i] = 1LL * ten[i-1] * 10;
    }
}

void solve(ll x,ll *cnt){
    int len = 0;
    while(x){
        num[++len] = x % 10;
        x = x/10;
    }
    for(int i=len;i>=1;i--){
        for(int j=0;j<=9;j++) cnt[j] += dp[i-1] * num[i];
        for(int j=0;j<num[i];j++) cnt[j] += ten[i-1];
        ll num2 = 0;
        for(int j=i-1;j>=1;j--) num2 = num2 * 10 + num[j];
        cnt[num[i]] += num2 + 1;
        cnt[0] -= ten[i-1];
    }
}
int main(){
    init();
    ll a,b; cin >> a >> b;
    solve(a-1,cnta); solve(b,cntb);
    for(int i=0;i<=9;i++) cout << cntb[i] - cnta[i] << " ";
    return 0;
}