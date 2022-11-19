#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int tree[N] = {0};
#define lowbit(x) (x&(-x))

// hdu 1556
void update(int x,int d){
    while(x<N){
        tree[x] += d;
        x += lowbit(x);
    }
}

int sum(int x){
    int ans = 0;
    while(x>0){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main(){
    int n; cin >> n;
    int m = n;
    while(m-->0){
        int l, r;
        cin >> l >> r;
        update(l,1);
        update(r+1,-1);
    }
    for(int i=1;i<=n;i++){
        cout << sum(i) << endl;
    }
    return 0;
}