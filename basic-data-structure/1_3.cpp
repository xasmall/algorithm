#include<bits/stdc++.h>
// 洛谷P1886
using namespace std;

const int N = 1e6 + 5;
int a[N];
deque<int> q;
int main(){
    int n,m; scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        while(!q.empty()&&a[q.back()]>a[i]) q.pop_back(); // 去尾
        q.push_back(i);
        if(i>=m){
            while(!q.empty()&&q.front()<=i-m) q.pop_front(); // 删头
            printf("%d ",a[q.front()]);
        }
    }
    printf("\n");
    q.clear();
    for(int i=1;i<=n;i++){
        while(!q.empty()&&a[q.back()]<a[i]) q.pop_back();
        q.push_back(i);
        if(i>=m){
            while(!q.empty()&&q.front()<=i-m) q.pop_front();
            printf("%d ",a[q.front()]);
        }
    }
    printf("\n");
    return 0;
    
}