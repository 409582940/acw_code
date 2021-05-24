/*
给定一个整数 n
，将数字 1∼n
 排成一排，将会有很多种排列方法。

现在，请你按照字典序将所有的排列方法输出。

输入格式

共一行，包含一个整数 n
。

输出格式

按字典序输出所有排列方案，每个方案占一行。

数据范围

1≤n≤7

输入样例：

3
输出样例：

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1


*/
#include <iostream>
using namespace std;
const int N = 10;
int n;
int p[N];
bool s[N];
void dfs(int u){
    if (u == n){
        for(int i =0;i<u;i++) cout << p[i] << " ";
        puts("");
    }
    for(int i =1;i<=n;i++){
        if(!s[i]){
        p[u] = i;
        s[i] = true;
        dfs(u+1);
        s[i] = false;
        }
        
     }
}
int main(){
    cin >> n;
    dfs(0);
    return 0;
}