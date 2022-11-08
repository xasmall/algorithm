#include<bits/stdc++.h>
using namespace std;

// hdu 1003
int main(){
    int t; scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n; scanf("%d",&n);
        int start = 1,end = 1, p = 1;
        int sum = 0;
        int maxSum = INT_MIN;
        for(int j=1;j<=n;j++){
            int a; scanf("%d",&a);
            sum += a;
            if(sum>maxSum){
                start = p;
                end = j;
                maxSum = sum;
            }
            if(sum<0){
                sum = 0;
                p = j + 1;
            }
        }
        printf("Case %d:\n",i);
        printf("%d %d %d\n",maxSum,start,end);
    }
}