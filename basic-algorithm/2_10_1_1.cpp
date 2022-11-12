#include<bits/stdc++.h>
using namespace std;

// 贪心

const int N = 3;
int coin[] = {1,2,5};
int ans[N] = {0};
int main(){
    int n;
    scanf("%d",&n);
    for(int i=N - 1 ;i>=0;i--){
        ans[i] = n / coin[i];
        n = n % coin[i];
    }
    for(int i=0;i<N;i++){
        printf("%d %d\n",coin[i],ans[i]);
    }
}