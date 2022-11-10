#include<bits/stdc++.h>

using namespace std;

// 反向扫描 尺取法 寻找数组中的两个数，它们两个的和等于给定目标数
const int N = 100005;
int s[N];
int main(){
    int n ; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
    }
    int m ; scanf("%d",&m);
    sort(s+1,s+n);
    int i = 1, j = n;
    while(i<j){
        int sum = s[i] + s[j];
        if(sum == m){
            break;
        }
        if(sum > m) j --;
        else i ++;
    }
    printf("%d %d\n",s[i],s[j]);
    return 0;
}