#include<bits/stdc++.h>
using namespace std;

// 洪水填充算法 hdu 1312
int a,b;
char mat[25][25];
int n,m;
#define check(x,y) (x>=1 && x<=n && y>=1 && y<=m)

void dfs(int x,int y){
    if(check(x,y)&&mat[x][y]!='#'&&mat[x][y]!='f'){
        mat[x][y] = 'f';
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
    }
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> mat[i] + 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mat[i][j] == '@'){ a = i; b = j;}
        }
    }
    dfs(a,b);
    int ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mat[i][j] == 'f') ans ++;
    cout << ans << endl;
}