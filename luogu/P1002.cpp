#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[25][25];
int dir[8][2] = {{-2,-1},{-2,1},{1,-2},{1,2},{-1,-2},{-1,2},{2,1},{2,-1}};

// dp递推

int main(){
    int a,b; cin >> a >> b;
    int x,y; cin >> x >> y;

    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            bool flag = true;
            for(int k=0;k<8;k++){
                if(((x+dir[k][0]) == i && (y + dir[k][1]) == j)||(x ==i && y==j)){
                    dp[i][j] = 0;
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(i==0 && j==0) dp[i][j] = 1;
                else{
                    dp[i][j] += i==0? 0 : dp[i-1][j];
                    dp[i][j] += j==0? 0 : dp[i][j-1];
                }   
            }
        }
    }
    cout << dp[a][b] << endl;
    
}