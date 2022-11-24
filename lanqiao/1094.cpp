#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n; cin.get();
    string s;
    int t = 0;
    while(getline(cin,s)){
        if(t < n) cout << s << endl;
        else{
            int i = 0;
            while(i<s.size()){
                if(s[i] == ' ') cout << endl << endl;
                else printf("%c",s[i]);
                i++;
            }
            cout << endl;
        }
        cout << endl;
        t++;
    }
}