#include<bits/stdc++.h>
using namespace std;

// hdu 4911 逆序对

const int N = 1e5 + 5;
typedef long long ll;
ll a[N],b[N],cnt;
void merge(ll l,ll mid,ll r){
    ll i = l, j = mid + 1, t = 0;
    while(i<=mid && j<=r){
        if(a[i]>a[j]){
            b[t ++] = a[j++];
            cnt += mid - i + 1;
        }else{
            b[t ++ ] = a[i++];
        }
    }
    while(i<=mid) b[t++] = a[i++];
    while(j<=r) b[t++] = a[j++];
    for(int i=0;i<t;i++){
        a[l + i] = b[i];
    }
}
void mergeSort(ll l,ll r){
    if(l<r){
        ll mid = (l + r) / 2;
        mergeSort(l,mid);
        mergeSort(mid + 1,r);
        merge(l,mid,r);
    }
}
int main(){
    ll n,k;
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    mergeSort(1,n);
    if(cnt<=k) printf("0\n");
    else  printf("%lld\n",cnt - k);
    return 0;
}