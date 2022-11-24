#include<bits/stdc++.h>
using namespace std;
char s[110][110];
int t[110][110];
int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
#define check(x,y) (x>=1&&x<=n&&y>=1&&y<=m)
int main(){
    int n,m;
    int pos = 1;
    while(cin >> n  >> m){
        for(int i=0;i<110;i++){
            memset(s[i],'\0',sizeof(s[i]));
            memset(t[i],0,sizeof(t[i]));
        }
        if(n == 0 && m == 0) return 0;
        for(int i=1;i<=n;i++) cin >> s[i] + 1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(s[i][j] == '*') t[i][j] = -1;
            }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t[i][j] == -1){
                    for(int p=0;p<8;p++){
                        int x = i + dir[p][0], y = j + dir[p][1];
                        if(check(x,y) && t[x][y]!=-1){
                            t[x][y] += 1;
                        }
                    }
                }
            }
        }
        cout << "Field #" << pos++ << ":" <<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t[i][j]==-1) printf("*");
                else printf("%d",t[i][j]);
            }
            cout << endl;
        }
        cout << endl;

    }
}