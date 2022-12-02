#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int s[N][4];


int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i][0] >> s[i][1] >> s[i][2] >> s[i][3];
    }
    int x,y; cin >> x >> y;
    int ans = -1;
    for(int i=1;i<=n;i++){
        int xmin = s[i][0],xmax = s[i][0] + s[i][2];
        int ymin = s[i][1],ymax = s[i][1] + s[i][3];
        if(x>=xmin && x<=xmax && y>=ymin && y <=ymax){
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}