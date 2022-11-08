#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> q;
int main(){
    int n; scanf("%d",&n);
    while(n-->0){
        int op; scanf("%d",&op);
        if(op==1){
            scanf("%d",&op);
            q.push(op);
        }else if(op == 2){
            printf("%d\n",q.top());
        }else{
            q.pop();
        }
    }
    return 0;
}