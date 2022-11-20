#include<bits/stdc++.h>
using namespace std;
const int N = 20005;
// hdu 1542
// 扫描线
int ls(int x){ return x << 1;}
int rs(int x){ return x << 1 | 1;}
int tag[N]; // 正数表示可以使用，0或者负数表示不能使用
double length[N];
double xx[N];
struct ScanLine{
    double y;
    double x_right;
    double x_left;
    int inout;
    ScanLine(){}
    ScanLine(double yy,double x1,double x2,int io){
        y = yy; x_right = x1; x_left = x2; inout = io;
    }
}line[N];
bool cmp(ScanLine &a,ScanLine &b){ return a.y < b.y;}
void push_up(int p,int l,int r){
    if(tag[p]) length[p] = xx[r] - xx[l];
    // 如果当前tag等于0，且当前的节点代表的区间只一个叶子节点，那显然这个区间的可使用长度为0
    else if(l + 1 == r) length[p] = 0;
    else length[p] = length[ls(p)] + length[rs(p)];
}
void update(int l,int r,int p,int tl,int tr,int io){
    if(l<=tl && r>=tr){
        tag[p] += io;
        push_up(p,tl,tr);
        return;
    }
    // 到达了叶子节点，返回，当前想要找的区间不能往下分了，且不满足上面的，所以返回
    if(tl + 1 == tr) return;
    int mid = tl + tr >> 1;
    if(l<=mid) update(l,r,ls(p),tl,mid,io);
    if(r>mid) update(l,r,rs(p),mid,tr,io); // 注意不是mid+1，因为线段中点没有长度
    push_up(p,tl,tr);
}
int main(){
    int n,t = 0;
    while(scanf("%d",&n),n){
        int cnt = 0;
        double x1,y1,x2,y2;
        while(n-->0){
            cin >> x1 >> y1 >> x2 >> y2;
            line[++cnt] = ScanLine(y1,x2,x1,1);
            xx[cnt] = x1;
            line[++cnt] = ScanLine(y2,x2,x1,-1);
            xx[cnt] = x2;
        }
        sort(xx+1,xx+1+cnt);
        sort(line+1,line+1+cnt,cmp);
        int num = unique(xx + 1,xx+1+cnt) - (xx + 1);
        memset(tag,0,sizeof(tag));
        memset(length,0,sizeof(length));
        double ans = 0;
        for(int i=1;i<=cnt;i++){
            int l,r;
            ans += length[1] * (line[i].y - line[i-1].y);
            l = lower_bound(xx+1,xx+num+1,line[i].x_left) - xx;
            r = lower_bound(xx+1,xx+num+1,line[i].x_right) - xx;
            update(l,r,1,1,num,line[i].inout);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++t,ans);
    }
    
}