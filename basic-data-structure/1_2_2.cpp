#include<bits/stdc++.h>

// 洛谷P1540 手写循环队列
using namespace std;
const int N = 1003;
int ha[N] = {0};
struct myqueue{
    int data[N];
    int head,rear;
    bool init(){
        head = rear = 0;
        return true;
    }
    int size(){ return (rear - head + N) % N;};
    bool empty(){
        if(size() == 0) return true;
        return false;
    }
    bool push(int e){
        if((rear + 1)%N == head) return false;
        data[rear] = e;
        rear = (rear + 1) % N;
        return true;
    }
    bool pop(int &e){
        if(head == rear) return false;
        e = data[head];
        head = (head + 1) % N;
        return true;
    }
    int front(){ return data[head]; }
}Q;
int main(){
    int m,n; scanf("%d%d",&m,&n);
    int cnt = 0;
    while(n-->0){
        int en; scanf("%d",&en);
        if(!ha[en]){
            cnt ++;
            Q.push(en);
            ha[en] = 1;
            while(Q.size() > m){
                int tmp; Q.pop(tmp);
                ha[tmp] = 0;
            }
        }
    }
    printf("%d\n",cnt);
}