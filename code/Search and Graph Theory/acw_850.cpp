#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e6 + 10;
int n,m;
int dist[N];
int e[N],ne[N],h[N],idx,w[N];
bool st[N];
void add(int a, int b, int c) 
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

/*int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII> > heap;
    heap.push({0,1});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second,distance = t.first;
        if (st[ver]) continue;
        for(int i = h[ver];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j]>distance+w[i]){
                dist[j] = distance+w[i];
                heap.push({dist[j],j});
            }
            
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}*/
int dijkstra()  // 求1号点到n号点的最短路距离，如果从1号点无法走到n号点则返回-1
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}



int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    cout << dijkstra() << endl;

    return 0;
}