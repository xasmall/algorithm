#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m; cin>>n>>m;
    list<int> node;
    for(int i=1;i<=n;i++) node.push_back(i);
    list<int>::iterator it = node.begin();
    while(n-->0){
        for(int i=1;i<m;i++){
            it++;
            if(it == node.end()) it = node.begin();
        }
        cout << *it << " ";
        list<int>::iterator next = ++it;
        if(next == node.end()) next = node.begin();
        node.erase(--it);
        it = next;
    }
    return 0;
}