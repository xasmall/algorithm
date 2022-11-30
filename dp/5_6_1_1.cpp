#include<bits/stdc++.h>
using namespace std;

// 区间dp luogu P1880

int n,min1,max1,f1[300][300],f2[300][300],num[300];
int s[300];
int d(int i,int j){ return s[j] - s[i-1]; }

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> num[i];
        num[i+n] = num[i];
    }
    for(int i=1;i<=2*n;i++){
        s[i] = s[i-1] + num[i];
    }
    for(int p=1;p<n;p++){
        for(int i=1,j=i+p;j<=2*n&&i<=2*n;i++,j++){
            f2[i][j] = 0x3f3f3f3f;
            for(int k=i;k<j;k++){
                f1[i][j] = max(f1[i][j],f1[i][k] + f1[k+1][j] + d(i,j));
                f2[i][j] = min(f2[i][j],f2[i][k] + f2[k+1][j] + d(i,j));
            }
        }
    }
    min1 = 0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        max1 = max(max1,f1[i][i+n-1]);
        min1 = min(min1,f2[i][i+n-1]);
    }
    cout << min1 << endl << max1 << endl;
    return 0;
}