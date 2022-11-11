#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int olda[N];
int newa[N];
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&olda[i]);
        newa[i] = olda[i];
    }
    sort(olda + 1,olda + 1 + n);
    int cnt = n;
    // cnt = unique(olda + 1,olda + 1 + n) -(old + 1); //  去重，cnt是去重后的数量
    for(int i=1;i<=n;i++){
        newa[i] = lower_bound(olda + 1,olda + 1 + n, newa[i]) - olda;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",newa[i]);
    }

}