#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 400040
const double PI = acos(-1.0);

struct Complex {
    double real, imag;
    Complex() {}
    Complex(double _real, double _imag)
        : real(_real)
        , imag(_imag) {}
    Complex operator-(const Complex &cp) const {
        return Complex(real - cp.real, imag - cp.imag);
    }
    Complex operator+(const Complex &cp) const {
        return Complex(real + cp.real, imag + cp.imag);
    }
    Complex operator*(const Complex &cp) const {
        return Complex(real * cp.real - imag * cp.imag, real * cp.imag + imag * cp.real);
    }
    void setValue(double _real = 0, double _imag = 0) {
        real = _real;
        imag = _imag;
    }
};

int len;
Complex wn[MAXN], wn_anti[MAXN];
void FFT(Complex y[], int op) {
    // Rader, 位逆序置换
    for (int i = 1, j = len >> 1, k; i < len - 1; ++i) {
        if (i < j) swap(y[i], y[j]);
        k = len >> 1;
        while (j >= k) {
            j -= k;
            k >>= 1;
        }
        if (j < k) j += k;
    }
    // h=1，Wn^0=1
    for (int h = 2; h <= len; h <<= 1) {
        // Wn = e^(2*PI*i/n)，如果是插值Wn = e^(-2*PI*i/n)，i虚数单位
        Complex Wn = (op == 1 ? wn[h] : wn_anti[h]);
        for (int i = 0; i < len; i += h) {
            Complex W(1, 0);
            for (int j = i; j < i + (h >> 1); ++j) {
                Complex u = y[j], t = W * y[j + (h >> 1)];
                y[j] = u + t;
                y[j + (h >> 1)] = u - t;
                W = W * Wn;
            }
        }
    }
    if (op == -1) {
        for (int i = 0; i < len; ++i) y[i].real /= len;
    }
}
void Convolution(Complex A[],int n) {
    // 初始化
    for (len = 1; len < (n << 1); len <<= 1)
        ;
    for (int i = n; i < len; ++i) {
        A[i].setValue();
    }
    // e^(θi) = cosθ+isinθ -> Wn = cos(2*PI/n)+isin(2*PI/n)
    for (int i = 0; i <= len; ++i) { // 预处理
        wn[i].setValue(cos(2.0 * PI / i), sin(2.0 * PI / i));
        wn_anti[i].setValue(wn[i].real, -wn[i].imag);
    }
    FFT(A, 1);
    for (int i = 0; i < len; ++i) {
        A[i] = A[i] * A[i];
    }
    FFT(A, -1);
}
Complex aa[400040];
long long num[400040];
int a[400040];
long long sum[400040];
long long l1,l2,T,n;
bool fu=false;
string s1,s2;
int main() {
   // ios::sync_with_stdio(false);
    cin>>T;
    while (T--){
        cin>>n;
        memset(num,0,sizeof(num));
        for(int i=0;i< n; i++){
            cin>> a[i];
            num[a[i]]++;
        }
        sort(a,a+n);
        int len1= a[n-1]+1;
        int len=1;
        while(len<2*len1)len<<=1;
        for(int i=0;i<len1;i++)
            aa[i].setValue(num[i],0);
        for(int i=len1;i<len;i++)
            aa[i].setValue(0,0);
        Convolution(aa,len1);
        for(int i=0;i<len;i++){
            num[i]=(long long)(aa[i].real+0.5);
         //  cout<<num[i]<<" ";

        }
        len = 2*a[n-1];
        for(int i=0;i<n;i++)
        num[a[i]+a[i]]--;
        for(int i=1;i<=len;i++){
            num[i]/=2;
        }
        sum[0]=0;
        for(int i=1;i<=len ;i++){
            sum[i]=sum[i-1]+num[i];
        }
        long long cnt = 0;
        for(int i=0;i<n;i++){
            cnt+=sum[len]-sum[a[i]];
            cnt-=(long long)(n-1-i)*i;
            cnt -= (n-1);
            cnt -= (long long) (n-1-i)*(n-i-2)/2;

        }
        long long tot = (long long ) n*(n-1)*(n-2)/6;
        printf("%.7lf\n",(double)cnt/tot);
    }
   

    return 0;
}