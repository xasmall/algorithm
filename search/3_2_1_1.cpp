#include<bits/stdc++.h>
using namespace std;

// BFS去重 BFS的原理时逐步扩展下一层，把扩展出的下一层节点放入队列中处理。在任意时刻，队列中只包含相邻
// 两层的点。如果这些点都不同，只能把所有点放入队列。

struct node{
    string s;
    int t;
    node(){}
    node(string ss,int tt){
        s = ss;
        t = tt;
    }
};
map<string,bool> mp;
queue<node> q;

void solve(){
    while(!q.empty()){
        node now = q.front();
        q.pop();
        string s = now.s;
        int t = now.t;
        if(s == "087654321"){
            cout << t << endl;
            break;
        } 
        int i;
        for(i = 0;i<10;i++){
            if(s[i]=='0') break;
        }
        for(int j=i-2;j<=i+2;j++){
            int k = (j + 9) % 9;
            if(k == i) break;
            string news = s;
            char tmp = news[i];
            news[i] = news[k];
            news[k] = tmp;
            if(!mp[news]){
                mp[news] = true;
                q.push(node(news,t + 1));
            }
        }
    }
}

int main(){
    string s = "012345678";
    q.push(node(s,0));
    mp[s] = true;
    solve();
    return 0;
}