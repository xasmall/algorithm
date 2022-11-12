#include<bits/stdc++.h>
using namespace std;

// 汉诺塔
int sum = 0;
int m;
// 把n个盘子的问题分治成两个子问题
/**
 * 1. 把x杆的n-1个盘子移动到y杆子，然后把第n个盘子移动到z杆子
 * 2. 把y杆子的n-1个盘子移动到z杆子
 * 
 * @param x 
 * @param y 
 * @param z 
 * @param n 
 */
void hanoi(char x,char y,char z,int n){
    if(n == 1) {
        sum ++;
        if(sum == m){
            cout << "#" << n <<": "<< x << "->" << z << endl;
        }
    }else{
        hanoi(x,z,y,n-1);
        sum ++; // x上的盘子移动到z上
        if(sum ==m )cout << "#" << n <<": "<< x << "->" << z << endl;
        // y上的盘子移动到z上
        hanoi(y,x,z,n-1);
    }
}
int main(){
    int n;
    scanf("%d%d",&n,&m);
    hanoi('a','b','c',n);
    cout << sum << endl;
    return 0;
}