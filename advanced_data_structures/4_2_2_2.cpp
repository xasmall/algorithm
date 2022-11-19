#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define lowbit(x) (x&(-x))
const int N = 1e5 + 10;
ll tree1[N], tree2[N];

// 洛谷 P3372 树状数组，区间修改，区间查询

void update1(ll x,ll d){
    while(x<N){
        tree1[x] += d;
        x += lowbit(x);
    }
}

void update2(ll x,ll d){
    while(x<N){
        tree2[x] += d;
        x += lowbit(x);
    }
}

ll sum1(ll x){
    ll ans = 0;
    while(x > 0){
        ans += tree1[x];
        x -= lowbit(x);
    }
    return ans;
}

ll sum2(ll x){
    ll ans = 0;
    while(x>0){
        ans += tree2[x];
        x -= lowbit(x);
    }
    return ans;
}

int main(){
    int n,m; cin >> n >> m;
    ll old = 0 , a;
    for(int i=1;i<=n;i++){
        cin >> a;
        update1(i,a-old);
        update2(i,(i-1)*(a-old));
        old = a;
    }
    while(m-->0){   
        ll q,l,r,d;
        cin >> q;
        if( q == 1){
            cin >> l >> r >> d;
            update1(l,d);
            update1(r + 1, -d);
            update2(l,(l-1) * d);
            update2(r + 1,-d * r);
        }else{
            cin >> l >> r;
            cout << r * sum1(r) - sum2(r) - (l - 1) * sum1(l-1) + sum2(l-1) << endl;
        }
    }
}