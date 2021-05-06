/*
给定一个长度为 n 的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序后的第 k 个数
输入格式
第一行包含两个整数 n 和 k。
第二行包含 n 个整数（所有整数均在 1∼109 范围内），表示整数数列。
输出格式
输出一个整数，表示数列的第 k 小数。
数据范围
1≤n≤100000,
1≤k≤n
输入样例：
5 3
2 4 1 5 3
输出样例：
3
*/
#include <iostream>
using namespace std;
const int N = 100010;
int q[N];
/*原始快排
void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
*/
//改进 ：
int quick_sort(int l, int r, int k)
{
    if (l == r)
        return q[l];
    int i = l - 1, j = r + 1, x = q[l];
    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    int ls = j - l + 1;
    if (k < ls)
    {
        return quick_sort(l, j, k);
    }
    return quick_sort(j + 1, r, k - ls);
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    cout << quick_sort(0, n - 1, k) << endl;
}