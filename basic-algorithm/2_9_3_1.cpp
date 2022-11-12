#include<bits/stdc++.h>
using namespace std;

// 快速排序 poj 2388
const int N = 1e4+10;
int a[N];
int quickSort(int l,int r,int k){
    int mid = a[l + (r - l)/2];
    int i = l - 1,j = r + 1;
    while(i<j){
        do{
            i++;
        }while(a[i]<mid);
        do{
            j--;
        }while(a[j]>mid);
        if(i<j) swap(a[i],a[j]);
    }
    // 保证进入下一步时至少存在两个值
    if(l<j && k<=j) return quickSort(l,j,k);
    if(j+1<r && k>j) return quickSort(j+1,r,k);
    return a[k];
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int k = (n + 1)/2;
    int ans = quickSort(1,n,k);
    printf("%d\n",ans);
    return 0;

}