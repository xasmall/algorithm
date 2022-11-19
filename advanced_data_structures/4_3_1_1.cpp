#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
 * @brief Lazy_tag
 * 若修改的时一个线段区间，就只对这个线段区间进行整体上的修改，其内部每个元素的内容先不做修改
 * 只有当这个线段区间的一致性被破坏时，才把变化值传递给下一层的子区间
 * push_down函数，解决多次区间修改时，区间修改冲突的问题
 */
const ll N = 1e5 + 10;
ll a[N],tree[4*N],tag[4*N]; //tag[i]表示第i个节点代表的区间的lazy_tag
ll ls(ll x){ return x << 1;}
ll rs(ll x){ return (x << 1) + 1;}
void push_up(ll x){
    tree[x] = tree[ls(x)] + tree[rs(x)];
}
void build(ll x,ll l,ll r){
    tag[x] = 0;
    if(l == r){
        tree[x] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(ls(x),l,mid);
    build(rs(x),mid + 1,r);
    push_up(x);
}
void add_tag(ll x,ll l,ll r,ll d){
    tag[x] += d;
    tree[x] += d*(r - l + 1);
}

void push_down(ll x,ll l,ll r){
    if(tag[x]){
        ll mid = (l + r) >> 1;
        add_tag(ls(x),l,mid,tag[x]);
        add_tag(rs(x),mid + 1,r,tag[x]);
        tag[x] = 0;
    }
}

void update(ll l,ll r,ll x,ll tl,ll tr,ll d){
    if(l<=tl&&r>=tr){
        // 对当前区间进行添加tag标记
        add_tag(x,tl,tr,d);
        return;
    }
    // x节点表示的区间为[tl,tr]
    push_down(x,tl,tr);
    ll mid = (tl + tr) >> 1;
    if(l<=mid) update(l,r,ls(x),tl,mid,d);
    if(r>mid) update(l,r,rs(x),mid + 1,tr,d);
    push_up(x);
}

ll query(ll l,ll r,ll tl,ll tr,ll x){
    if(l<=tl&&r>=tr){
        return tree[x];
    }
    // 没有直接覆盖，需要先将原有的tag向下转移
    push_down(x,tl,tr);
    ll mid = (tl + tr) >> 1;
    ll res = 0;
    if(l<=mid) res += query(l,r,tl,mid,ls(x));
    if(r>mid) res += query(l,r,mid+1,tr,rs(x));
    return res;
}
int main(){
    ll n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    while(m-->0){
        ll q,l,r,d;
        cin >> q;
        if(q==1){
            cin >> l >> r >> d;
            update(l,r,1,1,n,d);
        }else{
            cin >> l >> r;
            cout << query(l,r,1,n,1) << endl;
        }
    }
}