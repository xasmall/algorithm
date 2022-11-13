#include<bits/stdc++.h>
using namespace std;
struct node{
    char value;
    node *l,*r;
    node(char value = '#',node *l = NULL,node *r = NULL){
        this->value = value;
        this->l = l;
        this->r = r;
    }
};

void remove_tree(node *root){
    if(root == NULL) return;
    remove_tree(root->l);
    remove_tree(root->r);
    delete root;
}

int main(){
    node *A,*B,*C,*D,*E,*F,*G,*H,*I;
    A = new node('A');  B = new node('B');  C = new node('C');
    D = new node('D');  E = new node('E');  F = new node('F');
    G = new node('G');  H = new node('H');  I = new node('I');
    E->l = B; E->r = G;
    B->l = A; B->r = D;
    D->l = C;
    G->l = F; G->r = I;
    I->l = H;
    queue<node> q;
    q.push(*E);
    while(!q.empty()){
        node t = q.front();
        cout << t.value << " ";
        q.pop();
        if(t.l!=NULL) q.push(*(t.l));
        if(t.r!=NULL) q.push(*(t.r));
    }
    remove_tree(E);
    return 0;
}