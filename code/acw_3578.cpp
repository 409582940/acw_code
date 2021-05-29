#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 200010;
int n,m;
int w[N];
bool check(int mid)
{
    LL res = 0;
    for (int i = n / 2; i < n; i ++ )
        if (w[i] < mid)
            res += mid - w[i];
    return res <= m;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) scanf("%d", &w[i]);
    sort(w, w + n);
    int l = 0, r = 2e9;
    while (l < r)
    {
        int mid = (LL)(l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%d\n", r);
    return 0;
}