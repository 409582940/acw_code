    #include <iostream>
    #include <cstring>
    #include <algorithm>
    using namespace std;
    const int N = 210,M=10010,INF = 1e9;
    int n,m,q;
    int d[N][N],g[N][N];
    void flord(){ 
        for(int k = 1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    d[i][j]=min(d[i][j],d[k][j]+d[i][k]);
                }
            }
        }
    }
    int main(){
        scanf("%d%d%d",&n,&m,&q);
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=0;j++){
                if (i == j) d[i][j] = 0;
                else d[i][j] = INF;
            }
        }
        while (m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a][b] = min(g[a][b],c);
        }
        flord();
        while (q--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            int t = d[a][b];
            if (t > INF/2) puts("impossible");
            else printf("%d",t);
        }
        
    }