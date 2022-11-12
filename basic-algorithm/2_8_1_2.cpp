#include<bits/stdc++.h>
using namespace std;

const int N = 305;
// luogu P1093 排序

struct student{
    int id;
    int chinese;
    int math;
    int english;
    int sum;
}st[N];

bool cmp(struct student t1,struct student t2){
    if(t1.sum!=t2.sum) return t1.sum > t2.sum;
    else{
        if(t1.chinese != t2.chinese) return t1.chinese > t2.chinese;
        else return t1.id < t2.id;
    }
}

int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&st[i].chinese,&st[i].math,&st[i].english);
        st[i].id = i;
        st[i].sum = st[i].chinese + st[i].math + st[i].english;
    }
    sort(st+1,st+1+n,cmp);
    for(int i=1;i<=5;i++){
        printf("%d %d\n",st[i].id,st[i].sum);
    }
    return 0;
}