#include<bits/stdc++.h>
using namespace std;

// 同向扫描，滑动窗口

const int N = 100005;
int a[N];
int main(){
    int n ; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int m; scanf("%d",&m);
    int i = 1, j = 1;
    int sum = a[1];
    // 因为这里面保证了所有的数都是正数，才可以这样做
    while(j<=n){
        if(sum >= m){
            if(sum == m) printf("%d %d\n",i,j);
            sum -= a[i];
            i++;
            if(i > j){ sum = a[i]; j++;}
        }
        if(sum < m){
            j ++;
            sum += a[j];
        }
    }
    return 0;

}