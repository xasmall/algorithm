#include<bits/stdc++.h>
using namespace std;

// poj 1945 A*算法
const int N = 30007,SIZE =  1e6 + 10;
int n;
struct node{
    int x,y,g,h;
    bool operator < (const node & a) const {
        return g + h == a.g + a.h ? h > a.h : g + h > a.g + a.h;
    }
};
struct Node{
    int to,next,w;
};
struct hash_map{
    // 头节点
    int head[N],now;
    // 具体的存放位置
    Node a[SIZE];
    bool inset(int sta,int w){
        int x = sta % N;
        for(int i=head[x];i;i=a[i].next){
            if(a[i].to == sta){
                if(a[i].w <= w) return 0;
                a[i].w = w; return 1;
            }
        }
        // 没找到
        a[++now] = {sta,head[x],w};
        head[x] = now;
        return 1;
    }
}dict;

priority_queue<node> heap;
node now;
int gcd(int a,int b){ return b ? gcd(b,a%b) : a; }
void judge(int x,int y){
    if(x<y) swap(x,y);
    if(x>2*n) return;
    // y等于0，x无法减小了，必然不能到达
    if(x>n && y==0) return;
    if(x == y) return;
    if(x % gcd(x,y)) return;
    if(!dict.inset(x*50000 + y,now.g + 1)) return;
    int h = 0 , tx = x;
    while(tx < n) h++, tx <<= 1;
    heap.push({x,y,now.g + 1, h});
}

void A_star(){
    heap.push({1,0,0,0});
    while(!heap.empty()){
        now = heap.top(); heap.pop();
        if(now.x == n || now.y == n){
            cout << now.g << endl;
            return;
        }
        int a = now.x, b = now.y;
        // a*2
        judge(a*2,b); judge(a,a*2);
        // b*2;
        judge(a,b*2); judge(b*2,b);
        // a+b
        judge(a+b,b); judge(a,a+b);
        // |a-b|
        judge(abs(a-b),b); judge(a,abs(a-b));
    }
}

int main(){
    cin >> n;
    A_star();
    return 0;
}