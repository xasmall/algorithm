#include<bits/stdc++.h>
using namespace std;

// 洛谷P1540

const int N = 1005;
int ha[N] = {0};
queue<int> mem;
int main(){
    int m,n; scanf("%d%d",&m,&n);
    int cnt = 0;
    while(n-->0){
        int en; scanf("%d",&en);
        if(!ha[en]){
            cnt++;
            mem.push(en);
            ha[en] = 1;
            while(mem.size()>m){
                ha[mem.front()] = 0;
                mem.pop();
            }
        }
    }
    printf("%d\n",cnt);
}