#include<bits/stdc++.h>

using namespace std;


// 二维差分，luogu P3397
const int N = 1005;
int d[N][N] = {0};
int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    while(m-->0){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        d[x1][y1] ++;
        d[x1][y2+1] --;
        d[x2+1][y1] --;
        d[x2+1][y2+1] ++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
}
