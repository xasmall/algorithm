#include<bits/stdc++.h>

struct node{
    int data;
    node * next;
};

int main(){
    int n, m; scanf("%d%d",&n,&m);
    node *head, *p, *prev, *now;
    head = new node; head->data = 1; head->next = NULL;
    now = head;
    for(int i=2;i<=n;i++){
        p = new node; p->data = i; p->next = NULL;
        now->next = p;
        now = p;
    }
    now->next = head;
    // 上面是创建动态链表，下面进行操作
    prev = now;
    now = head;
    while(n-->0){
        for(int i=1;i<m;i++){
            prev = now;
            now = now->next;
        }
        printf("%d ",now->data);
        prev->next = now->next;
        delete now;
        now = prev->next;
    }
    return 0;
}
