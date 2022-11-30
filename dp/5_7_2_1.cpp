#include<bits/stdc++.h>
using namespace std;

// 树形dp luoguP2016
const int N = 1510;
int n;
int f[N][2];
int v[N];
vector<int> s[N];

void dp(int x){
    f[x][0] = 0;
    f[x][1] = 1;
    if(s[x].size() == 0) return;
    for(int i=0;i<s[x].size();i++){
        int y = s[x][i];
        dp(y);
        f[x][0] += f[y][1];
        f[x][1] += min(f[y][1],f[y][0]);
    }
}


int main(){
    cin >> n;
    int a,b;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        int c;
        while(b-->0){
            cin >> c;
            s[a].push_back(c);
            v[c] = 1;
        }
    }
    int root;
    for(int i=0;i<n;i++){
        if(!v[i]){
            root = i; break;
        }
    }
    dp(root);
    cout << min(f[root][0],f[root][1]) << endl;
    return 0;
}