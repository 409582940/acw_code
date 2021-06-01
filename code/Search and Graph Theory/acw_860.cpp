#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e6;
int n,m;
int e[N],ne[N],h[N],idx;
int color[N];
bool dfs(int u,int c){
    color[u] = c;
    for(int i = h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!color[j]){
            if (!dfs(j,3-c)) return false;
        }else if (color[j] == c) return false;
    }
    return true;
}
int add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while (m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    bool flag = true;
    for(int i = 0;i<n;i++){
        if(!color[i]){
            if(!dfs(i,1)){
                flag = true;
                break;
            }
        }

    }
    if (flag) puts("Yes");
    else puts("No");
    return 0;

}