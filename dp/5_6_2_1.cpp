#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int num[250];
ll f[300][300];

// 区间dp 洛谷P1063

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> num[i];
        num[i+n] = num[i];
    }
    num[2*n+1] = num[1];

    for(int p=1;p<=n;p++){
        for(int i=1,j=i+p;i<=2*n&&j<=2*n;i++,j++){
            for(int k=i;k<j;k++){
                f[i][j] = max(f[i][j],f[i][k] + f[k+1][j]  + num[i] * num[k+1] * num[j+1]);
            }
        }
    }
    ll amax = 0;
    for(int i=1;i<=n;i++){
        amax = max(amax,f[i][i+n-1]);
    }
    cout << amax << endl;
}
