/*
问题描述：
给定 n 个区间 [li,ri]，要求合并所有有交集的区间。
注意如果在端点处相交，也算有交集。
输出合并完成后的区间个数。
例如：[1,3] 和 [2,6] 可以合并为一个区间 [1,6]。
输入格式
第一行包含整数 n。
接下来 n 行，每行包含两个整数 l 和 r。
输出格式
共一行，包含一个整数，表示合并区间完成后的区间个数。
数据范围
1≤n≤100000,
−109≤li≤ri≤109
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int l = -2e9, r = -2e9;
    for (auto item : segs)
        if (r < item.first)
        {
            if (l != -2e9)
                res.push_back({l, r});
            l = item.first;
            r = item.second;
        }
        else
            r = max(r, item.second);
    if (l != -2e9)
        res.push_back({l, r});
    segs = res;
}
int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}