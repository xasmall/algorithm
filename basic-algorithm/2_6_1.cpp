#include<bits/stdc++.h>
using namespace std;

// 差分，一维
const int N = 1e5 + 5;
int n;
int d[N] = {0};
int main(){

    scanf("%d",&n);
    int f = n;
    while(n-->0){
        int l, r;
        scanf("%d%d",&l,&r);
        d[r+1] --;
        d[l] ++;
    }
    for(int i=2;i<=f;i++){
        d[i] = d[i] + d[i-1];
    }
    for(int i=1;i<=f;i++){
        printf("%d\n",d[i]);
    }
    return 0;

}