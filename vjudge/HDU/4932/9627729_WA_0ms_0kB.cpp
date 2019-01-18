#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
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
bool cmp(double x,double y){
    return x>y;
}
vector<double> q;
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
        for(int i=1;i<=N-1;i++){
            rr=a[i+1]-a[i];
            q.push_back(double(rr));
        }
        sort(q.begin(),q.end(),cmp);
        double ans=-1000;
    for(int i=0;i<q.size();i++){
        if (check(q[i])){
            ans = max (ans,q[i]);
        }
        else if (check(q[i]/2)){
            ans = max (ans,q[i]/2);
        }
    }
        printf("%.3lf\n",ans);

    }
    return 0;
}