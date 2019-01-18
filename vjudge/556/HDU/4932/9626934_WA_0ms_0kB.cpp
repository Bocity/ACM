#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[100];
int main(){
    int t;
    cin>>t;
    long long  N,minn;
    while(t--){
        cin>>N;
        minn = 100000000000;
        for(int i=1;i<=N;i++)
        cin>>a[i];
        sort(a+1,a+1+N);
        long long l=1, r=-20000000000;
        for(int i=1;i<=N-2;i++){
            r=max(a[i+1]-a[i],a[i+2]-a[i+1]);
            minn = min(r,minn);
        }
        printf("%lld\n",minn);
    }
    return 0;
}