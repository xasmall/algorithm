#include<bits/stdc++.h>
using namespace std;

// 剪枝，如果前面的元素和已经大于了sum，后面的直接剪掉即可
int n,sum;
int path[20];
int Cn[20];
int vis[20];
bool flag = false;
int getSum(int t){
    int ans = 0;
    for(int i=1;i<=t;i++){
        ans += Cn[i] * path[i];
    }
    return ans;
}
void dfs(int x){
    if(flag) return;
    if(x == n + 1){
        int ans = getSum(n);
        if(ans == sum){
            for(int i=1;i<=n;i++){
                cout << path[i] << " ";
            }
            cout << endl;
            flag = true;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            path[x] = i;
            vis[i] = 1;
            int ans = getSum(x);
            if(ans<=sum){
                dfs(x+1);
            }
            vis[i] = 0;
        }
    }
}
int main(){
    scanf("%d%d",&n,&sum);
    Cn[1] = Cn[n] = 1;
    // 计算系数
    for(int i=2;i<n;i++){
        Cn[i] = Cn[i-1]*(n - i + 1) / (i-1); 
    }
    dfs(1);
}