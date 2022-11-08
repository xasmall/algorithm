#include<bits/stdc++.h>

using namespace std;

// 一维数组实现单向静态链表

int nodes[105];
int main(){
    int n,m; scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        nodes[i] = i + 1;
    }
    nodes[n] = 1;
    int now = 1,prev = n;
    while(n-->0){
        for(int i=1;i<m;i++){
            prev = now;
            now = nodes[now];
        }
        printf("%d ",now);
        nodes[prev] = nodes[now];
        now = nodes[prev];
    }
    return 0;
}