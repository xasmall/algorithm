#include<bits/stdc++.h>
using namespace std;

// hdu 1828
const int N = 200005;
int ls(int x) { return x << 1;}
int rs(int x) { return x << 1 | 1;}
struct ScanLine{
    int l,r,y,inout;
    ScanLine(){}
    ScanLine(int ll,int rr,int yy,int io):
        l(ll),r(rr),y(yy),inout(io){}
}line[N];
bool cmp(ScanLine &a,ScanLine &b){ return a.y < b.y;}
bool lbd[N<<2],rbd[N<<2];
int num[N<<2];
int tag[N<<2];
int length[N<<2];
void push_up(int p,int l,int r){
    if(tag[p]){
        lbd[p] = rbd[p] = 1;
        length[p] = r - l;
        num[p] = 1;
    }else if(l + 1  == r) {
        length[p] = lbd[p] = rbd[p] = num[p] = 0;
    }
    else{
        lbd[p] = lbd[ls(p)];
        rbd[p] = rbd[rs(p)];
        length[p] = length[ls(p)] + length[rs(p)];
        num[p] = num[ls(p)] + num[rs(p)];
        if(lbd[rs(p)] && rbd[ls(p)]) num[p] -= 1;
    }
}
void update(int l,int r,int p,int tl,int tr,int io){
    if(l<=tl && r>=tr){
        tag[p] += io;
        push_up(p,tl,tr);
        return;
    }
    if(tl + 1 == tr) return; // 如果到达了根节点，且没有满足上面的条件，就不往下走了
    int mid = tl + tr >> 1;
    if(l<=mid) update(l,r,ls(p),tl,mid,io);
    if(r>mid) update(l,r,rs(p),mid,tr,io); // 注意 因为是线段，所以不能是mid + 1
    push_up(p,tl,tr);
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        int cnt = 0;
        int xmin = INT_MAX, xmax = INT_MIN;
        for(int i=1;i<=n;i++){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            xmin = min(xmin,x1);
            xmax = max(xmax,x2);
            line[++cnt] = ScanLine(x1,x2,y1,1);
            line[++cnt] = ScanLine(x1,x2,y2,-1);
        }
        sort(line + 1,line+1+cnt,cmp);
        int ans = 0,last = 0;
        for(int i=1;i<=cnt;i++){
            if(line[i].l<line[i].r){
                update(line[i].l,line[i].r,1,xmin,xmax,line[i].inout);
            }
            ans += num[1] * 2 * (line[i+1].y - line[i].y);
            ans += abs(length[1] - last);
            last = length[1];
        }
        printf("%d\n",ans);
    }
}
