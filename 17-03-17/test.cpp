#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 262144
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
void Convolution(Complex A[], Complex B[], int n) {
    // 初始化
    for (len = 1; len < (n << 1); len <<= 1)
        ;
    for (int i = n; i < len; ++i) {
        A[i].setValue();
        B[i].setValue();
    }
    // e^(θi) = cosθ+isinθ -> Wn = cos(2*PI/n)+isin(2*PI/n)
    for (int i = 0; i <= len; ++i) { // 预处理
        wn[i].setValue(cos(2.0 * PI / i), sin(2.0 * PI / i));
        wn_anti[i].setValue(wn[i].real, -wn[i].imag);
    }
    FFT(A, 1);
    FFT(B, 1);
    for (int i = 0; i < len; ++i) {
        A[i] = A[i] * B[i];
    }
    FFT(A, -1);
}
Complex a[200005], b[200005];
long long r[50005],l[50005],rl[200005],t,tt,ans,x,y,m,n,q,T;
int main() {
    ios::sync_with_stdio(false);
    cin>>T;
    int c=0;
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(r,0,sizeof(r));
        memset(l,0,sizeof(l));
        memset(rl,0,sizeof(rl));
        ans=0;
        c++;
        cin>>m>>n>>q;
        t=tt=0;
        while (q--)
        {
            cin>>x>>y;
            r[x]=1;
            l[y]=1;
            rl[x-y+n]=1;
        }
        for(int i=1;i<=m;i++)if (!r[i]) t++;
        for(int i=1;i<=n;i++)if (!l[i]) tt++; 
        ans=t*tt;
        for(int i=1;i<=m;i++)if (!r[i]) a[i].real=1;
        for(int i=1;i<=n;i++)if (!l[i]) b[n-i].real=1; 
        Convolution(a,b,max(m,n)+1);
        for(int i=0;i<len;++i) ans-=(long long)(a[i].real+0.5)*rl[i];
        cout<<"Case "<<c<<": "<<ans<<"\n";

    }    
    return 0;
}
