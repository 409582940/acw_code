#include <iostream>
#include <algorithm>
using namespace std;
int n;
void divide(int x){
    for(int i = 2;i<=x/i;i++){//最多只包含一个大于根号n的质因子
        if(x%i == 0){
            int s = 0;
            while(x%i == 0){//除到i不是因数为止
                x = x/i;
                s++;
            }
            cout << i << " " << s << endl;
        }
    }
    if (x > 1) cout << x << " " << 1 << endl; // 如果是质数，输出这个数和1 或者是输出大于根号n的质因子 

    cout << endl;
}
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        int x = 0;
        cin >> x;
        divide(x);
    }
    return 0;
}