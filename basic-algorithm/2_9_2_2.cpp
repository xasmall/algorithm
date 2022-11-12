#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N],b[N];
void merge(int l ,int mid ,int r){
    int i = l , j = mid + 1, t = 0;
    while(i<=mid && j <= r){
        if(a[i]>a[j]){
            b[t++] = a[j++];
        }else{
            b[t++] = a[i++];
        }
    }
    while(i<=mid){
        b[t++] = a[i++];
    }
    while(j<=r){
        b[t++] = a[j++];
    }
    for(int i=0;i<t;i++){
        a[l + i] = b[i];
    }
}
void mergeSort(int l ,int r){
    if(l<r){
        int mid = l + r >> 1;
        mergeSort(l,mid);
        mergeSort(mid+1,r);
        merge(l,mid ,r);
    }
}
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    mergeSort(1,n);
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}