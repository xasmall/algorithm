#include<bits/stdc++.h>
using namespace std;

// next_permutation 全排列函数，函数的排列范围为[first,last),包括first，不包括last
// 如果要得到所有的全排列，需要从最小的全排列开始，如果初始的全排列不是最小的，先用sort函数排序，再适用next_permutation函数

int main(){
    string s = "abc";
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(),s.end()));
    return 0;
}