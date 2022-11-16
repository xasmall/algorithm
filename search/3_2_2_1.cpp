#include<bits/stdc++.h>
using namespace std;

// poj 3278
struct node{
    int x;
    int t;
    node(){}
    node(int xx ,int tt){ x = xx; t = tt;}
};
queue<node> q;
map<int,bool> mp;
int k;
void solve(){
    int ans = 0;
    while(!q.empty()){
        node now = q.front();
        q.pop();
        int x = now.x, t = now.t;
        if(x == k){ cout << t << endl; break; }
        if(!mp[x-1]){
            mp[x-1] = true;
            q.push(node(x-1,t + 1 ));
        }
        if(x<k){
            if(!mp[x+1]){
                q.push(node(x+1,t+1));
                mp[x+1] = true;
            }
            if(!mp[2*x]){
                mp[2*x] = true;
                q.push(node(2*x,t+1));
            }
        }
    }
}
int main(){
    int n;
    cin >> k >> n;
    q.push(node(n,0));
    mp[n] = true;
    solve();
    return 0;
}