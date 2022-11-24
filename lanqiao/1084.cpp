#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
bool st[N];

int main(){
    int n ; cin >> n;
    for(int i=2;i<=sqrt(n);i++){
        if(!st[i]){
            for(int j=2;i*j<=n;j++){
                st[i*j] = true;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(!st[i]) cout << i << endl;
    }
    return 0;
}