#include<bits/stdc++.h>
using namespace std;


const int N = 100005;

// 洛谷P2947

struct mystack{
    int a[N];
    int t = 0;
    void push(int x) { a[++t] = x;}
    int top(){ return a[t];}
    void pop(){ t--;}
    int empty(){ return t ==0?1:0;}
}st;
int h[N],a[N];
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    for(int i=n;i>=1;i--){
        while(!st.empty()&&h[st.top()]<=h[i]) st.pop();
        if(st.empty()) a[i] = 0;
        else a[i] = st.top();
        st.push(i);
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}