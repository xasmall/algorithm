#include<bits/stdc++.h>

using namespace std;

// 反向扫描，判断是否是回文串

int main(){
    int n ; scanf("%d",&n);
    while(n-->0){
        string s;
        cin >> s;
        bool ans = true;
        int i = 0 , j = s.size() - 1;
        while(i<j){
            if(s[i]!=s[j]){
                ans = false;
                break;
            }else{
                 i++;
                 j--;
            }
        }
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}