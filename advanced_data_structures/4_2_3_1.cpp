#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 10;
int tree[N],r[N],n;
#define lowbit(x) (x&(-x))

struct point{
    int num;
    int val;
}a[N];

void update(int x,int d){
    while(x<N){
        tree[x] += d;
        x += lowbit(x);
    }
}
long long sum(int x){
    long long ans = 0;
    while(x>0){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

bool cmp(point x,point y){
    if(x.val == y.val) return x.num < y.num;
    else return x.val < y.val;
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].val;
        a[i].num = i;
    }
    sort(a + 1, a + 1 + n,cmp);
    for(int i=1;i<=n;i++) r[a[i].num] = i;
    long long ans = 0;
    for(int i=n;i>=1;i--){
        update(r[i],1);
        ans += sum(r[i] - 1);
    }
    cout << ans << endl;
    return 0;
}