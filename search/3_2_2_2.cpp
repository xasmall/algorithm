#include<bits/stdc++.h>
using namespace std;

// hdu 1010
char mat[8][8];
int vis[8][8] = {0};
int n,m,t;
int flag;
int a,b,c,d;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
#define check(xx,yy) (xx>=1&&xx<=n&&yy>=1&&yy<=m)
void dfs(int x,int y,int time){
    if(flag) return;
    if(mat[x][y] == 'D'){
        if(time == t){
            flag = 1;
            return;
        }
    }
    int tmp = t - time - abs(c-x) - abs(d-y);
    if(tmp<0) return;
    if(tmp%2==1) return;
    for(int i=0;i<4;i++){
        int xx =  x + dir[i][0], yy = y +  dir[i][1];
        if(check(xx,yy)&&mat[xx][yy]!='X'&&vis[xx][yy]==0){
            vis[xx][yy]  = 1;
            dfs(xx,yy,time + 1);
            vis[xx][yy] = 0;
        }
    }
    return;
}
int main(){
    cin >> n >> m >> t;
    for(int i=1;i<=n;i++){
        cin >> mat[i] + 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mat[i][j] == 'S'){ a = i; b = j;}
            if(mat[i][j] == 'D'){ c = i; d = j;}
        }
    }
    flag = 0;
    dfs(a,b,0);
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}