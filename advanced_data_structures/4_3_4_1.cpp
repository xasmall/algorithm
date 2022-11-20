#include<bits/stdc++.h>
using namespace std;
// hdu 4027
#define ll long long
const int N = 1e5 + 10;
ll tree[N<<2],a[N];
ll ls(ll x){ return x << 1 ;}
ll rs(ll x){ return (x << 1) + 1;}
void build(ll x,ll l, ll r){
    if(l == r){
        tree[x] = a[l]; return ;
    }
    ll mid = (l + r) >> 1;
    build(ls(x),l,mid);
    build(rs(x),mid + 1,r);
    tree[x] = tree[ls(x)] + tree[rs(x)];
}

void update(ll l,ll r,ll x,ll tl,ll tr){
    if(l > tr || r < tl) return;
    if(tl == tr && l <=tl && r >= tr){
        tree[x] = sqrt(1.0 * tree[x]);
        return;
    }
    // 如果当前区间的和是区间大小，必然不能再往下除
    if(tree[x] == (tr - tl + 1)) return;
    ll mid = tl + tr >> 1;
    if(l<=mid) update(l,r,ls(x),tl,mid);
    if(r>mid) update(l,r,rs(x),mid + 1,tr);
    tree[x] = tree[ls(x)] + tree[rs(x)];
}
ll query(int l,int r,int x,int tl,int tr){
    if(l<=tl && r >= tr) return tree[x];
    int mid = tl + tr >> 1;
    ll res = 0;
    if(l<=mid) res += query(l,r,ls(x),tl,mid);
    if(r > mid) res += query(l,r,rs(x),mid + 1,tr);
    return res;
}
int main(){
    ll n;
    while(~scanf("%d",&n)){
        for(ll i=1;i<=n;i++){ cin >> a[i];}
        build(1,1,n);
        int m; cin >> m;
        int t,x,y;
        while(m-->0){
            cin >> t >> x >> y;
            if(t == 0) update(x,y,1,1,n);
            else cout << query(x,y,1,1,n) << endl;
        }
    }
}