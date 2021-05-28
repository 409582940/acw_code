//排序
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
const int N = 1010,M=2000010;
int a[M];
void fast_sort(int b[],int l,int r){
    if(l>=r) return;
    int i = l - 1 , j = r + 1,x = b[(l+r)>>1];
    while (i<j)
    {
        do i++ ; while (b[i]<x);
        do j-- ; while (b[i]>x);
        if (i<j) swap(b[i],b[j]);
    }
    fast_sort(b,l,j),fast_sort(b,j+1,r);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i<m;i++){
        scanf("%d",&a[i]);
    }
    fast_sort(a,0,m-1);
    for(int i = 0;i<m;i++){
        printf("%d ",a[i]);
    }
    return 0;
}