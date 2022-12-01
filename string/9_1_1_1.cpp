#include<bits/stdc++.h>
using namespace std;

// BKDRHash luogu P3370

/**
 * 对于区间[l,R]的哈希值的代码可以这样写
 * ull get_hash(ull l, ull r){ return H[R] - H[L-1] * P[R-L+1];}
*/
#define ull unsigned long long
ull a[10010];
char s[10010];
ull BKDRHash(char * s){
    ull P = 131, H = 0;
    int n = strlen(s);
    for(int i=0;i<n;i++){
        H = H * P + s[i] - 'a' + 1;
    }
    return H;
}

int main(){
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        a[i] = BKDRHash(s);
    }
    int ans = 0;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]!=a[i+1]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}