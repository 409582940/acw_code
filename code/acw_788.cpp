/*
给定一个长度为 n 的整数数列，请你计算数列中的逆序对的数量。
逆序对的定义如下：对于数列的第 i 个和第 j 个元素，如果满足 i<j 且 a[i]>a[j]，则其为一个逆序对；否则不是。
输入格式
第一行包含整数 n，表示数列的长度。
第二行包含 n 个整数，表示整个数列。
输出格式
输出一个整数，表示逆序对的个数
数据范围
1≤n≤100000
输入样例：
6
2 3 4 5 6 1
输出样例：
5
*/
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n;
int q[N], temp[N];
LL marge_sort(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = l + r >> 1;
    LL res = marge_sort(l, mid) + marge_sort(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            temp[k++] = q[i++];
        else
        {
            res += mid - i + 1;
            temp[k++] = q[j++];
        }
    }
    while (i <= mid)
        temp[k++] = q[i++];
    while (j <= r)
        temp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = temp[j];
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    cout << marge_sort(0, n - 1) << endl;
}
