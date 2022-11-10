#include<bits/stdc++.h>
using namespace std;

// 最大值最小化 二分
const int N = 100005;
int a[N];
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int l = 1, r = 1e8;
    while(l<r){
        int m = l + r >> 1;
        // 划分
        int sum = 0;
        int t = 0;
        for(int i=1;i<=n;i++){
            if(a[i] > m){
                t = 4;
                break;
            }
            if(sum + a[i] > m){
                sum = a[i];
                t ++;
            }else if(sum + a[i] == m){
                sum = 0;
                t ++;
            }else{
                sum += a[i];
            }
        }
        if( t <=3 ) r = m;
        else l = m + 1;
    }
    cout << l << endl;
    return 0;
}