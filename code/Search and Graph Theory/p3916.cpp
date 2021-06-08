#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int e[N],ne[N],h[N],idx;
int n,m;
bool st[N];
int res;
void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
int dfs(int u){
    st[u] = true;
    for(int i = h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(st[j]) continue;
        dfs(j);
        res = max(res,j);
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    for(int i = 1;i<=n;i++){
        int t = dfs(i);
        printf("%d ",t);
    }
    return 0;
}