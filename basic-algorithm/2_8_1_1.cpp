#include<bits/stdc++.h>
using namespace std;

bool my_less(int i,int j){ return i<j; }
bool my_greater(int i,int j){ return i>j; }

int main(){
    vector<int> a = {3,5,1,3,4,6,2};
    // 默认排序
    // sort(a.begin(),a.begin() + a.size());
    // 按照从大到小排序
    // sort(a.begin(),a.begin() + a.size(), greater<int>());
    // 适用自定义函数，从小到大排序
    // sort(a.begin(),a.begin() + a.size(),my_less);
    // 适用自定义函数，从大到小排序
    // sort(a.begin(),a.begin() + a.size(),my_greater);

    // 前四个数字从大到小排序，其他顺序不变
    sort(a.begin(),a.begin() + 4,greater<int>());

    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }

}