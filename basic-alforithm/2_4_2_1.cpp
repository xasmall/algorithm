#include<bits/stdc++.h>
using namespace std;

// 洛谷P3382
const double eqs =  1e-6;
double a[15];
int n;
double f(double x){
    double ans = 0;
    // n+1个系数，最多乘x n次
    for(int i=n;i>=0;i--){
        ans = ans * x + a[i];
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    double l, r;
    scanf("%lf%lf",&l,&r);
    for(int i=n;i>=0;i--) scanf("%lf",&a[i]);
    // 三等分法
    while(r - l > eqs){
        double k = ( r - l )/ 3.0;
        double mid1 = l + k, mid2 = r - k;
        if(f(mid1)>f(mid2)) r = mid2;
        else l = mid1;
    }
    printf("%.5f\n",l);
    return 0;
}