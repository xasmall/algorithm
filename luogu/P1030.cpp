#include<bits/stdc++.h>
using namespace std;
void beford(string m,string e){
    if(m.size()>0){
        char ch = e[e.size()-1];
        cout<< ch;
        int k = m.find(ch);
        beford(m.substr(0,k),e.substr(0,k));
        beford(m.substr(k+1),e.substr(k,e.size()-k-1));
    }
}
int main(){
    string m,e;
    cin>> m;
    cin>> e;
    beford(m,e);
}