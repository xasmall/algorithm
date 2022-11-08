#include<bits/stdc++.h>
using namespace std;

const int N = 5000;
struct node{
    char data;
    int l, r;
}tree[N];
char s[N];
char judge(int start,int end){
    int a1 = 0, a2 = 0;
    int n = end - start + 1;
    for(int i=start;i<=end;i++){
        if(s[i]=='1') a1++;
        if(s[i]=='0') a2++;
    }
    if(a1 == n) return 'I';
    if(a2 == n) return 'B';
    return 'F';
} 
int buildTree(int i,int start,int end){
    if(start>end) return 0;
    if(start == end){
        tree[i].data = judge(start,end);
        tree[i].l = 0;
        tree[i].r = 0;
        return i;
    }
    int mid = (start + end) / 2;
    tree[i].data = judge(start,end);
    tree[i].l = buildTree(i*2,start,mid);
    tree[i].r = buildTree(i*2+1,mid + 1,end);
    return i;
}
void travese(int i){
    if(i==0) return;
    travese(tree[i].l);
    travese(tree[i].r);
    printf("%c",tree[i].data);
}

int main(){
    int n; scanf("%d",&n);
    scanf("%s",s+1);
    int end = pow(2,n);
    buildTree(1,1,end);
    travese(1);
}