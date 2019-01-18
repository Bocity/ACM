#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
double eps=1e-6;
bool f[1000]={0};
int a[100];
    long long  N,minn;
bool check(double x){
            memset(f,0,sizeof f);
    for(int i=2;i<=N-1;i++){
        if ((a[i]-a[i-1]>=x&&!f[i-1])||(f[i-1]&&a[i]-a[i-1]>=2*x))
        {
                continue;
        }
        else{
            if (a[i+1]-a[i]<x){
                return false;
            }
            else{
                f[i]=true;
            }
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>N;
        minn = 200000000000;
        for(int i=1;i<=N;i++)
        cin>>a[i];
        sort(a+1,a+1+N);
        long long  rr=-20000000000;
        for(int i=1;i<=N-2;i++){
            rr=max(a[i+1]-a[i],a[i+2]-a[i+1]);
            minn = min(rr,minn);
        }
        double l=1;
        double r=minn;
       // cout<<r;
    //    if (check(r)){
    //     printf("%.3lf\n",r);
    //    }
    for(double i=r;i>=0.5;i-=0.5){
        if (check(i)){
            printf("%.3lf\n",r);
            break;
        }
    }

    }
    return 0;
}