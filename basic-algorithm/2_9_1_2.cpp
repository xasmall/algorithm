#include<bits/stdc++.h>
using namespace std;

// 快速幂 注意: 快速幂的标准写法并不是分治，而是利用基于二进制的倍增法

typedef long long ll;
ll fastPow(ll a,ll n,ll m){
    if(n == 0) return 1;
    if(n == 1) return a;
    ll tmp = fastPow(a,n/2,m);
    if(n % 2 == 1) return tmp * tmp * a % m;
    else return tmp * tmp % m;
}

int main(){
    ll a , n ,m;
    scanf("%lld %lld %lld",&a,&n,&m);
    printf("%lld\n",fastPow(a,n,m));
}