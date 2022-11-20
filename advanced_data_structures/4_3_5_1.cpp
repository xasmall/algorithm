#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
// hdu 5306
ll sum[N<<2];
int ma[N<<2],se[N<<2],num[N<<2];// num表示区间的最大值的个数
int ls(int x){ return x<<1; }
int rs(int x){ return x<<1|1;}
void push_up(int p){
    sum[p] = sum[ls(p)] + sum[rs(p)];
    ma[p] = max(ma[ls(p)],ma[rs(p)]);
    if(ma[ls(p)]==ma[rs(p)]){
        se[p] = max(se[ls(p)],se[rs(p)]);
        num[p] = num[ls(p)] + num[rs(p)];
    }else{
        se[p] = max(se[ls(p)],se[rs(p)]);
        se[p] = max(se[p],min(ma[ls(p)],ma[rs(p)]));
        num[p] = ma[ls(p)] > ma[rs(p)] ? num[ls(p)] : num[rs(p)];
    }
}
void build(int x,int l,int r){
    if(l == r){
        scanf("%lld",&sum[x]);
        ma[x] = sum[x]; se[x] = -1; num[x] = 1;
        return; 
    }
    int mid = l + r >> 1;
    build(ls(x),l,mid);
    build(rs(x),mid+1,r);
    push_up(x);
}

void add_tag(int p,int x){
    if(x>=ma[p]) return;
    // 否则，必然减少这么多
    sum[p] = sum[p] - 1LL * num[p] * (ma[p] - x);
    ma[p] = x;
}
// push_down，往下一层转移
void push_down(int p){
    add_tag(ls(p),ma[p]);
    add_tag(rs(p),ma[p]);
}
void update(int l,int r,int p,int tl,int tr,int x){
    if(x>=ma[p]) return;
    if(l<=tl && r>=tr && se[p] < x){
        add_tag(p,x); return;
    }
    push_down(p); // 原有的tag清零
    int mid = tl + tr >> 1;
    if(l<=mid) update(l,r,ls(p),tl,mid,x);
    if(r>mid) update(l,r,rs(p),mid+1,tr,x);
    push_up(p);
}
int query_max(int l,int r,int p,int tl,int tr){
    if(l<=tl && r >= tr) return ma[p];
    push_down(p);
    int mid = tl + tr >> 1;
    int res = -1;
    if(l<=mid) res = max(res,query_max(l,r,ls(p),tl,mid));
    if(r>mid) res = max(res,query_max(l,r,rs(p),mid+1,tr));
    return res;
}
ll query_sum(int l,int r,int p,int tl,int tr){
    if(l<=tl && r >= tr) return sum[p];
    push_down(p);
    int mid = tl + tr >> 1;
    ll res = 0;
    if(l<=mid) res += query_sum(l,r,ls(p),tl,mid);
    if(r>mid) res += query_sum(l,r,rs(p),mid+1,tr);
    return res;
}
int main(){
    int t; scanf("%d",&t);
    while(t-->0){
        int n,m; scanf("%d%d",&n,&m);
        build(1,1,n);
        int q,l,r,x;
        while(m-->0){
            scanf("%d",&q);
            if(q==0){
                scanf("%d%d%d",&l,&r,&x);
                update(l,r,1,1,n,x);
            }else if(q == 1){
                scanf("%d%d",&l,&r);
                printf("%d\n",query_max(l,r,1,1,n));
            }else{
                scanf("%d%d",&l,&r);
                printf("%lld\n",query_sum(l,r,1,1,n));
            }
        }
    }
}