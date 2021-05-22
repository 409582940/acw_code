/*
我们规定，对于一个整数 a
，如果其各位数字相加之和能够被 4
 整除，则称它是一个特殊数字。
现在，给定一个整数 n
，请你计算并输出不小于 n
 的最小特殊数字。
输入格式
一个整数 n。
输出格式
一个整数，表示不小于 n
 的最小特殊数字。
数据范围
对于 30%
 的数据，1≤n≤100。
对于 100%
 的数据，1≤n≤1000
输入样例：
42
输出样例：
44
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    
    int n;
    cin >> n;
    if (n == 1000) cout << 1003 << endl;
    int a = n / 100; //baiwei
    int b = n / 10 - a*10;
    int c = n - a*100 - b*10;
    while((a + b + c)%4 != 0){
        if (c == 10) c = 0,b++;
        if (b == 10) b = 0,a++;
        c+=1;
    }
    cout << a*100+b*10+c << endl;
    return 0;
}
