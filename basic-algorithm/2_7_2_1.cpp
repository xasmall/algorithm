#include<bits/stdc++.h>
using namespace std;

// 手动实现离散化

const int N = 500010;

struct data{
    int val;
    int id;
}olda[N];

int newa[N];
bool cmp(data x,data y){
    return x.val < y.val;
}

int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&olda[i].val);
        olda[i].id = i;
    }
    sort(olda+1,olda + 1 + n,cmp);
    for(int i = 1;i<=n;i++){
        newa[olda[i].id] = i;
        if(olda[i].val == olda[i-1].val){
            newa[olda[i].id] = newa[olda[i-1].id];
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",newa[i]);
    }
    return 0;
}