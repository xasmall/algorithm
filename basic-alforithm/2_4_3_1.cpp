#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
int n,m;
int t[N],p[N];
ll a,b,c;
ll calc1(int f){
    ll x = 0 , y = 0;
    for(int i=1;i<=m;i++){
        if(p[i]>f) x += p[i] - f;
        else y += f - p[i];
    }
    if(a<b) return min(x,y) * a + (x - min(x,y)) * b;
    else return x * b;
}
// f指最后一门课程的时间，两个不愉悦度的产生是没有关联的
ll calc2(int f){
    ll sum = 0;
    for(int i=1;i<=n;i++){
        if(t[i] < f) sum += (f - t[i]) * c;
    }
    return sum;
}

int main(){
    scanf("%lld%lld%lld",&a,&b,&c);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    for(int i=1;i<=m;i++) scanf("%d",&p[i]);
    sort(t+1,t+n+1); sort(p+1,p+m+1);
    if( c >= 1e16){
        printf("%lld\n",calc1(t[1]));
        return 0;
    } 
    ll l = 1 , r = N;
    while( r - l > 2){
        int mid1 = l + (r - l )/3 , mid2 = r - (r - l) /3;
        ll c1 = calc1(mid1) + calc2(mid1);
        ll c2 = calc1(mid2) + calc2(mid2);
        if(c1 > c2){
            l = mid1;
        }else{
            r = mid2;
        }
    }
    ll ans = 1e18;
    for(int i=l;i<=r;i++){
        ll x = calc1(i) + calc2(i);
        ans = min(ans,x);
    }
    printf("%lld\n",ans);
    return 0;
}
