#include<bits/stdc++.h>
using namespace std;
// 食物链 带权值的并查集

const int N = 50005;
int p[N],d[N]; // 0同类，1吃，2被吃
int n,ans;
void init(){
    for(int i=0;i<=n;i++){
        p[i] = i;
        d[i] = 0;
    }
}
int find(int x){
    if(x != p[x]){
        int t = p[x];
        p[x] = find(p[x]);
        d[x] = (d[x] + d[t]) % 3;
    }
}
void merge(int x,int y,int v){
    int fa = find(x), fb = find(y);
    if(fa == fb){
        if(v!=(d[x] - d[y] + 3)%3) ans ++;
    }else{
        p[fa] = p[fb];
        d[fa] = (v + d[fb] - d[fa] + 3) % 3;
    }
}
int main(){
    int k;
    cin >> n >> k;
    ans = 0;
    init();
    while(k-->0){
        int x,y,v;
        cin >> v >> x >> y;
        v --;
        if(x>n || y >n || (v ==1 && x==y)) ans ++;
        merge(x,y,v);
    }
    cout << ans << endl;
}
