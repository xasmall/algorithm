#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ks = 0;
    int pre = -1;
    while(cin >> n){
        while(n){
            int pos = ks + 1;
            int t = pos + 1; // 每一行初始的分割
            int s = pre == -1 ? 1 : pre + ks;
            pre = s;
            for(int i=1;i<=n;i++){
                printf("%d ",s);
                s += t;
                t ++;
            }
            printf("\n");
            n--;
            ks ++;
            
        }
    }
    return 0;
}