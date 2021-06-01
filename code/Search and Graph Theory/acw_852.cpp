#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 100010;
int n,m;
int dist[N],cnt[N];
bool st[N];
int e[N],ne[N],w[N],idx,h[N];
void add(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}
bool spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    for (int i = 1; i <= n; i ++ ){
        st[i] = true;
        q.push(i);
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if (dist[j]>dist[t]+w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] =  cnt[t] + 1;
                if (cnt[j]>n) return true;
                if(!st[j])
                q.push(j);
                st[j] = true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m -- ) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a, b, c);
    }
    if (spfa()) puts("Yes");
    else puts("No");
    return 0;
}