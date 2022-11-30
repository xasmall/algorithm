#include<bits/stdc++.h>
using namespace std;

int f[55][55];
char s[55];
// 区间dp 洛谷 P4170

int main(){
    scanf("%s",s+1);
    int n = strlen(s+1);
    memset(f,0x3f3f3f,sizeof(f));
    for(int i=1;i<=n;i++){
        f[i][i] = 1;
    }
    for(int p=1;p<n;p++){
        for(int i=1,j=i+p;i<=n&&j<=n;i++,j++){
            if(s[i]==s[j]) f[i][j] = min(f[i+1][j],f[i][j-1]);
            else
            for(int k=i;k<j;k++){
                f[i][j] = min(f[i][j],f[i][k] + f[k+1][j]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}