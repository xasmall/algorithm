#include<bits/stdc++.h>

using namespace std;

const int N = 105;

struct node{
    int id,nextid;
}nodes[N];

int main(){
    int n,m; scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        nodes[i].id = i;
        nodes[i].nextid = i + 1;
    }
    nodes[n].nextid = 1;
    int now = 1,prev = n;
    while(n-->0){
        for(int i=1;i<m;i++){
            prev = now;
            now = nodes[now].nextid;
        }
        printf("%d ",nodes[now].id);
        nodes[prev].nextid = nodes[now].nextid;
        now = nodes[prev].nextid;
    }
    return 0;
}