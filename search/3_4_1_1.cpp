#include<bits/stdc++.h>
using namespace std;
#define check(x,y) (x>=1&&x<=n&&y>=1&&y<=m)
// BFS最短路径 迷宫

struct node{
    int x;
    int y;
    node(int xx,int yy){ x = xx; y = yy;}
};
char mp[31][51];
char k[4] = {'D','L','R','U'};
// D L R U
int dir[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};
int vis[31][51] = {0};
char pre[31][51];
int n,m;

void print_path(int x,int y){
    if(x == 1 && y == 1) return;
    if(pre[x][y] == 'D') print_path(x-1,y);
    if(pre[x][y] == 'L') print_path(x,y+1);
    if(pre[x][y] == 'R') print_path(x,y-1);
    if(pre[x][y] == 'U') print_path(x+1,y);
    cout << pre[x][y] << " ";
}
void bfs(){
    queue<node> q;
    vis[1][1] = 1;
    q.push(node(1,1));
    while(!q.empty()){
        node now = q.front();
        q.pop();
        if(now.x == n && now.y == m){
            print_path(n,m);
            return ;
        }
        for(int i=0;i<4;i++){
            int xx = now.x + dir[i][0], yy = now.y + dir[i][1];
            if(check(xx,yy) && mp[xx][yy] != '1' && vis[xx][yy] == 0){
                vis[xx][yy] = 1;
                pre[xx][yy] = k[i];
                q.push(node(xx,yy));
            }
        }

    }
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> mp[i] + 1;
    bfs();
}