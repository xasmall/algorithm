#include<bits/stdc++.h>
using namespace std;

int a[10] = {1,2,3,4,5,6,7};
bool vis[10];
int b[10];
void dfs(int s,int t){
    if(s == t){
        for(int i=0;i<t;i++) cout << b[i] << " ";
        cout << endl;
        return;
    }
    for(int i=0;i<t;i++){
        if(!vis[i]){
            // 如果不设置它是否被适用，那么这个数字可以无限适用
            vis[i] = true;
            b[s] = a[i];
            dfs(s+1,t);
            vis[i] = false;
        }
    }
}
int main(){
    int n = 4;
    dfs(0,4);
    return 0;
}