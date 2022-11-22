#include<bits/stdc++.h>
using namespace std;
// P3372 分块
const int N = 1e5+10;
const int M = 1e3 + 10;
int n;
int block,t;
int st[M],ed[M],pos[N],a[N],sum[M],add[M];
void init(){
    block = sqrt(n);
    int t = n / block;
    if(n%block) t++;
    for(int i=1;i<=t;i++){
        st[i] = (i-1) * block + 1;
        ed[i] = i * block;
    }
    ed[t] = n;
    for(int i=1;i<=n;i++){
        pos[i] = (i-1)/block + 1;
    }
    for(int i=1;i<=t;i++){
        for(int j=st[i];j<=ed[i];j++){
            sum[i] += a[j];
        }
    }
}
void change(int l,int r,int d){
    int p = pos[l], q = pos[r];
    if(p==q){
        for(int i=l;i<=r;i++){
            a[i] += d;
        }
        sum[p] += (r-l + 1) * d;
    }else{
        for(int i=p+1;i<=q-1;i++) add[i] += d;
        for(int i=l;i<=ed[p];i++) a[i] += d;
        sum[p] += d*(ed[p] - l + 1);
        for(int i=st[q];i<=r;i++) a[i] += d;
        sum[q] += (r - st[q] + 1) * d;
    }
}
long long ask(int l,int r){
    int p = pos[l],q = pos[r];
    long long ans = 0;
    if(p==q){
        for(int i=l;i<=r;i++) ans += a[i];
        ans += 1LL * add[p] * (r-l +1);
    }else{
        for(int i=p+1;i<=q-1;i++) ans += sum[i] + add[i]*(ed[i] - st[i] + 1);
        for(int i=l;i<=ed[p];i++) ans += a[i];
        ans += 1LL * add[p] * (ed[p] - l + 1);
        for(int i=st[q];i<=r;i++) ans += a[i];
        ans += 1LL *  add[q] * (r - st[q] + 1);
    }
    return ans;
}
int main(){
    int m; cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    init();
    int q,l,r,d;
    while(m-->0){
        cin >> q;
        if(q == 1){
            cin >> l >> r >> d;
            change(l,r,d);
        }else{
            cin >> l >> r;
            cout << ask(l,r) << endl;
        }
    }
    return 0;
}