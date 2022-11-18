#include <bits/stdc++.h>
using namespace std;

// hdu 3038 带权并查集
const int N = 2 * 1e5 + 10;
int p[N], d[N];
int n,m,ans;
void init(){
    for(int i=0;i<=n;i++){
        p[i] = i;
        d[i] = 0;
    }
}
int find(int x){
    if(x!=p[x]){
        int t = p[x];
        p[x] = find(p[x]);
        d[x] += d[t];
    }
    return p[x];
}
void merge(int a,int b,int v){
    int fa = find(a), fb = find(b);
    if(fa == fb){
        if(d[a] - d[b] != v) ans ++;
    }else{
        p[fa] = p[fb];
        // v + d[b]是 a到fb的权值， d[a]是a到fa的权值 相减之后就是 fa到fb的权值
        d[fa] = v + d[b] - d[a];
    }
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        init();
        while(m-->0){
            ans = 0;
            int a,b,v;
            // 形成左开右闭的区间
            scanf("%d%d%d",&a,&b,&v);
            a --;
            merge(a,b,v);
        }
        printf("%d\n",ans);
    }
}
