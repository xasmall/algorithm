#include<bits/stdc++.h>
using namespace std;
const int N = 6009;
int n;
int h[N];
int v[N];
int f[N][2];
vector<int> s[N];
// 树形dp 洛谷P1352

void dp(int x){
    f[x][0] = 0;
    f[x][1] = h[x];
    for(int i=0;i<s[x].size();i++){
        int y = s[x][i];
        dp(y);
        f[x][0] += max(f[y][0],f[y][1]);
        f[x][1] += f[y][0];
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> h[i];

    int a,b;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        s[b].push_back(a);
        v[a] = 1;
    }
    int root;
    for(int i=1;i<=n;i++){
        if(!v[i]){
            root = i;break;
        }
    }
    dp(root);
    cout << max(f[root][0],f[root][1]) << endl;
    return 0;
}