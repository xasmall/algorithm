#include<bits/stdc++.h>
using namespace std;

// 手写静态二叉树，BFS遍历
const int N = 1e5+5;
struct node{
    char value;
    int lson,rson;
}tree[N];

// 记录当前可用的空节点的下标，从1开始使用
int index = 1;

int newNode(char val){
    tree[index].value = val;
    tree[index].lson = 0; // 0表示不用，即为空节点
    tree[index].rson = 0;
    return index ++;
}
void insert(int father,int child,int l_r){
    if(l_r==0) tree[father].lson = child;
    else tree[father].rson = child;
}
int buildTree(){
    int A = newNode('A'); int B = newNode('B'); int C = newNode('C');
    int D = newNode('D'); int E = newNode('E'); int F = newNode('F');
    int G = newNode('G'); int H = newNode('H'); int I = newNode('I');
    insert(E,B,0); insert(E,G,1); insert(B,A,0); insert(B,D,1);
    insert(D,C,0); insert(G,F,0); insert(G,I,1); insert(I,H,0);
    int root = E;
    return root;
}

int main(){
    int root = buildTree();
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int tmp = q.front();
        cout << tree[tmp].value << " ";
        q.pop();
        if(tree[tmp].lson != 0) q.push(tree[tmp].lson);
        if(tree[tmp].rson != 0) q.push(tree[tmp].rson);
    }
    return 0;
}
