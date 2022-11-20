#include<bits/stdc++.h>
using namespace std;

// hdu 4614 二分+线段树
const int N = 5 * 1e4 + 10;

int tree[N<<2],tag[N<<2],a[N];
int ls(int x){ return x << 1 ;}
int rs(int x){ return (x << 1) + 1;}
void push_down(int x,int l,int r){
    if(tag[x]!=-1){
        tag[ls(x)] = tag[rs(x)] = tag[x];
        int mid = l + r >> 1;
        tree[ls(x)] = (mid - l + 1) * tag[ls(x)];
        tree[rs(x)] = (r - mid) * tag[rs(x)]; 
        tag[x] = -1;
    }
}
void build(int x,int l,int r){
    // 初始的lazy标记是-1
    tag[x] = -1;
    if(l == r){
        // tree[x] 记录x这个区间的空闲花瓶的个数
        tree[x] = 1;
        return;
    }
    int mid = l + r >> 1;
    build(ls(x),l,mid);
    build(rs(x),mid+1,r);
    tree[x] = tree[ls(x)] + tree[rs(x)];
    return;

}
void update(int l,int r,int x,int tl,int tr,int v){
    if(l<=tl && r >= tr){
        tree[x] = v * (tr - tl + 1);
        tag[x] = v;
        return;
    }
    push_down(x,tl,tr);
    int mid = tl + tr >> 1;
    if(l<=mid) update(l,r,ls(x),tl,mid,v);
    if(r>mid) update(l,r,rs(x),mid + 1,tr,v);
    tree[x] = tree[ls(x)] + tree[rs(x)];
}
int query(int l,int r,int x,int tl,int tr){
    if(l<=tl&&r>=tr){
        return tree[x];
    }
    push_down(x,tl,tr);
    int mid = tl + tr >> 1;
    int res = 0;
    if(l<=mid) res += query(l,r,ls(x),tl,mid);
    if(r>mid) res += query(l,r,rs(x),mid+1,tr);
    return res;
}

int query_pos(int a,int n,int sum){
    int l = a, r = n;
    while(l<r){
        int mid = l + r >> 1;
        if(query(a,mid,1,1,n)>=sum) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    int t; cin >> t;
    while(t-->0){
        memset(tag,-1,sizeof(tag));
        int n,m; cin >> n >> m;
        build(1,1,n);
        int q,a,b;
        while(m-->0){
            cin >> q >> a >> b;
            if(q==1){
                int sum = query(a+1,n,1,1,n);
                if(sum<1){
                    cout << "Can not put any one." << endl;
                }
                // 先找到第一花瓶的位置
                else{
                    int firstPos = query_pos(a+1,n,1);
                    int endPos;
                    if( sum>= b){
                        endPos = query_pos(a+1,n,b);
                    }else{
                        endPos = query_pos(a+1,n,sum);
                    }
                    cout << firstPos-1 << " " << endPos-1 << endl;
                    update(firstPos,endPos,1,1,n,0);
                }
            }else{
                update(a+1,b+1,1,1,n,1);
            }
            
        }
    }
}