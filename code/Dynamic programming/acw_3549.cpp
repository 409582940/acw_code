/*
给定一个长度为 n
 的数字序列 a1,a2,…,an
，序列中只包含数字 1
 和 2
。
现在，你要选取一个区间 [l,r](1≤l≤r≤n)
，将 al,al+1,…,ar
 进行翻转，并且使得到的新数字序列 a
 的最长非递减子序列的长度尽可能长。

请问，这个最大可能长度是多少？

一个非递减子序列是指一个索引为 p1,p2,…,pk
 的序列，满足 p1<p2<…<pk
 并且 ap1≤ap2≤…≤apk
，其长度为 k
。

输入格式

第一行一个整数 n
。

第二行 n
 个空格隔开的数字 1
 或 2
，表示 a1,…,an
。

输出格式

输出一个整数，表示得到的新数字序列 a
 的最长非递减子序列的最大可能长度。

数据范围

对于 30%
 的数据，1≤n≤100
。
对于 100%
 的数据，1≤n≤106
。
本题读入数据规模较大，需注意优化读入。
C++ 尽量使用 scanf 读入，Java 尽量使用 BufferedReader 读入。

输入样例1：

4
1 2 1 2
输出样例1：

4
输入样例2：

10
1 1 2 2 2 1 1 2 2 1
输出样例2：

9

*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    while (n -- )
    {
        int x;
        scanf("%d", &x);
        if (x == 1)
        {
            s1 = s1 + 1;
            s3 = max(s3 + 1, s2 + 1);
        }
        else
        {
            s2 = max(s1 + 1, s2 + 1);
            s4 = max(s3 + 1, s4 + 1);
        }
    }

    printf("%d\n", max(s3, s4));
    return 0;
}