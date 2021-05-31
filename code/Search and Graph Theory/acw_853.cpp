    #include <iostream>
    #include <cstring>
    #include <algorithm>
    using namespace std;
    const int N = 1000,M=10010;
    int dist[N],backup[N];
    int n,m,k;
    struct Edge{
        int a,b,w;
    }edges[M];
    int bellman_ford(){
        memset(dist,0x3f,sizeof dist);
        dist[1] = 0;
        for(int i = 0;i<k;i++){
            memcpy(backup,dist,sizeof dist);
            for(int j = 0;j<m;j++){
                auto e = edges[j];
                dist[e.b] = min(dist[e.b],backup[e.a]+e.w);
            }
        }
        
        if (dist[n]>0x3f3f3f3f /2) return -1;
        else return dist[n];
    }


    int main()
    {
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 0; i < m; i ++ ){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            edges[i]={a,b,w};
        }
        int t = bellman_ford();
        if (t == -1) puts("impossible");
        else cout << t << endl;
        return 0;
    }