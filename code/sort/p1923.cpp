//第k小的数
#include <iostream>
using namespace std;
const int N = 5000010;
int q[N];
int sort(int q[],int l,int r,int k){
    if (l>=r) return q[l];
    int i = l - 1,j = r + 1, x = q[(l+r)>>1];
    while(i<j){
        do i++ ; while (q[i]<x);
        do j-- ; while (q[i]>x);
        if (i<j) swap(q[i],q[j]);
    }
    if (j - l + 1 >= k) return sort(q, l, j, k);
    else return sort(q, j + 1, r, k - (j - l + 1));
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++){
        scanf("%d",&q[i]);
    }
    cout << sort(q,0,n-1,k)<<endl;
    return 0;
}