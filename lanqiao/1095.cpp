#include<bits/stdc++.h>
using namespace std;
int tmax = 1;
const int N = 1e6 + 10;
int mem[N];
int clac(int x){
    if(x == 1) return 1;
    if(x < N && mem[x] != -1) return mem[x];
    int t;
    if(x%2==0){
        t = clac(x/2) + 1;
    }else{
        t = clac(x*3+1) + 1;
    }
    if(x < N){
        mem[x] = t;
    }
    return t;
}

int main(){
    int l,r;
    int a,b;
    memset(mem,-1,sizeof(mem));
    mem[1] = 1;
    while(~scanf("%d%d",&l,&r)){
        if(l>r) {
            a = r;
            b = l;
        }else{
            a = l;
            b = r;
        }
        tmax = -1;
        for(int i=a;i<=b;i++){
            int t = clac(i);
            tmax = max(tmax,t);
        }
        cout << l << " " << r << " " << tmax << endl;
    }
    return 0;
}