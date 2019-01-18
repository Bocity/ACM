#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
ll MOD;
long long pow(long long a, long long b, long long p) { // return a^b %p
    if (b==0) return 1%p;
    long long t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
const int N = 2;
struct Mat {
    ll mat[N][N]; //每个Mat使用前都要memset 。  否则会出现奇奇怪怪的错误
};
Mat operator*(Mat a, Mat b) {
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for (k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
            }
        }
    }
    return c;
}
Mat operator^(Mat a, int k) {
    Mat c;
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j) c.mat[i][j] = (i == j);

    for (; k; k >>= 1) {
        if (k & 1) c = c * a;
        a = a * a;
    }
    return c;
}

long long a[100000];
long long b[100000];
long long n,m,ans;
long long a1;

int main(){
    ios::sync_with_stdio(false);
    Mat aaa;
    Mat aaa1;
    aaa.mat[0][0]=4;
    aaa.mat[0][1]=1;
    aaa.mat[1][0]=0;
    aaa.mat[1][1]=0;
    aaa1.mat[0][0]=4;
    aaa1.mat[0][1]=2;
    aaa1.mat[1][0]=0;
    aaa1.mat[1][1]=0;
   Mat p;
   Mat q;
    while(cin>>n>>m){
        MOD=m;
        memset(p.mat,0,sizeof p.mat);
        a1= 1%m;
        if (n==1){
            cout<<1%m<<endl;
            continue;
        }
        if (n==2){
            cout<<2%m<<endl;
            continue;
        }
        if (n&1){
            long long N=(n+1)/2;
            long long x=pow(2,n-1,m);
            p.mat[0][0]=1;
            p.mat[1][0]=1;
            q=(aaa^(N-2))*p;

            ans = (x)%m+q.mat[0][0];
        }
        else{
            long long N=n/2;
            long long x=pow(2,n-1,m);
            p.mat[0][0]=2;
            p.mat[1][0]=1;
            q=(aaa1^(N-2))*p;
            ans = x%m+q.mat[0][0];
        }
        cout<<ans%m<<endl;
    }
    return 0;
}