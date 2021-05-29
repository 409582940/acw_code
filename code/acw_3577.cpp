#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int n,m;
int a[N],b[N];
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i = 0;i<m;i++){
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    cout << a[n-1] << b[m-1] << endl;
}