#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; getline(cin,s);
    int i = 0, j = s.size() - 1;
    while(i<j){
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
    cout << s << endl;
}