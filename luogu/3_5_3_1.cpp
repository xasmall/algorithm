#include<bits/stdc++.h>
using namespace std;

// 双向bfs
struct node{
    string s;
    int t;
    node(string ss,int tt){s = ss, t = tt;};
};
string s,e;
map<string,bool> mp1;
map<string,bool> mp2;

void switchCase(queue<node> &q,map<string,bool> &mp,node &now){
    for(int i=0;i<now.s.size();i++){
        string ss = now.s;
        if(ss[i] == '9') ss[i] = '1';
        else ss[i] += 1;
        q.push(node(ss,now.t + 1));
        mp[ss] = true;

        ss = now.s;
        if(ss[i] == '1') ss[i] = '9';
        else ss[i] -= 1;
        q.push(node(ss,now.t+1));
        mp[ss] = true;
    }
    // 相邻的两个数字进行交换
    for(int i=0;i<now.s.size()-1;i++){
        string  ss = now.s;
        char tmp = ss[i];
        ss[i] = ss[i+1];
        ss[i+1] = tmp;
        q.push(node(ss,now.t+1));
        mp[ss] = true;
    }
}

void bfs(){
    queue<node> q1 , q2;
    q1.push(node(s,0));
    q2.push(node(e,1));
    mp1[s] = true; mp2[e] = true;
    int l1 = 0 ,l2 = 0;
    while(!q1.empty() && !q2.empty()){
        int s1 = q1.size();
        int s2 = q2.size();
        if(s1>s2){
            // 扩展q2
            while(s2-->0){
                node now = q2.front(); q2.pop();
                if(mp1[now.s]){
                    cout << l1 + l2  << endl;
                    return;
                }
                switchCase(q2,mp2,now);
            }
            l2++;
        }else{
            while(s1-->0){
                node now = q1.front(); q1.pop();
                if(mp2[now.s]){
                    cout << l1 + l2  << endl;
                    return ;
                }
                switchCase(q1,mp1,now);
            }
            l1 ++;
        }
    }
}

int main(){
    cin >> s >> e;
    bfs();
    return 0;
}