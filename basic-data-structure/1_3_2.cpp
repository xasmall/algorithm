#include<bits/stdc++.h>

// acwing 135 有限制的最大子序列和
using namespace std;
const int N = 300005;
long long s[N];
deque<int> dp;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i]);
    }
    for(int i=1;i<=n;i++){
        s[i] = s[i-1] + s[i];
    }
    long long maxSum = -1ll;
    dp.push_back(0);
    for(int i=1;i<=n;i++){
        while(!dp.empty()&&dp.front()<i-m) dp.pop_front();
        if(dp.empty()) maxSum = max(maxSum,s[i]);
        else maxSum = max(maxSum,s[i] - s[dp.front()]);
        while(!dp.empty()&&s[dp.back()]>=s[i]) dp.pop_back();
        dp.push_back(i);
    }
    cout << maxSum <<endl;
}