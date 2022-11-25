#include<bits/stdc++.h>
using namespace std;

// luogu 1776 多重背包
const int N = 1e5 + 10;
int n,C,dp[N];
int new_n;
int new_w[N],new_c[N];
int main(){
    cin >> n >> C;
    int a, b, c;
    new_n = 0;
    for(int i=1;i<=n;i++) {
        cin >> a >> b >> c;
        for(int j=1;j<=c;j<<=1){
            new_w[++new_n] = j * a;
            new_c[new_n] = j * b;
            c -= j;
        }
        if(c){
            new_c[++new_n] = c * b;
            new_w[new_n] = c * a;
        }
    }
   
    for(int i=1;i<=new_n;i++){
        for(int j=C;j>=new_c[i];j--){
            dp[j] = max(dp[j],dp[j-new_c[i]]+new_w[i]);
        }
    }
    cout << dp[C] << endl;
}