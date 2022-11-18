#include<bits/stdc++.h>
using namespace std;
// hdu 1213
const int N = 1020;
int p[N];
int cnt;
// 路径压缩
int find(int x){
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    int fa = find(a), fb = find(b);
    if(fa!=fb) {
        p[fa] = p[fb];
        cnt --;
    }
}

int main(){
    int t,n,m,x,y;
    cin >> t;
    while(t-->0){
        cin >> n >> m;
        for(int i=1;i<=n;i++) p[i] = i;
        cnt = n;
        while(m-->0){
            cin >> x >> y;
            merge(x,y);
        }
        cout << cnt << endl;
    }
}