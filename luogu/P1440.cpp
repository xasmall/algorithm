#include<bits/stdc++.h>
using namespace std;

deque<int> q;
const int N = 2 * 1e6 + 5;
int s[N];
int main(){
    int n,m; scanf("%d%d",&n,&m);
    int min = INT_MAX;
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
    }    
    for(int i=1;i<=n;i++){
        while(!q.empty()&&q.front()<i-m) q.pop_front();
        if(q.empty()) printf("%d\n",0);
        else printf("%d\n",s[q.front()]);
        while(!q.empty()&&s[q.back()]>=s[i]) q.pop_back();
        q.push_back(i);
    }
    return 0;
}