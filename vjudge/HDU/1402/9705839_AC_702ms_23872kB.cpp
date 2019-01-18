#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
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
Complex a[500000], b[500000];
int ans[500000];
int l1,l2;
bool fu=false;
string s1,s2;
int main() {
    ios::sync_with_stdio(false);
    while (cin >> s1 >> s2) {
        //cout<<"s1:"<<s1<<"s2"<<s2<<"\n";
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ans,0,sizeof(ans));
        fu=true;
        if ((s1=="0")||(s2=="0")) {cout<<"0\n";continue;}
        if (s1[0]!='-'&&s2[0]!='-')fu=false;
        if (s1[0]=='-'&&s2[0]=='-')fu=false;
        l1=s1.length() - 1;
        l2=s2.length() - 1;
        int q = max(s1.length() - 1, s2.length() - 1);
        for (int i = s1.length() - 1;s1[i]!='-'&& i >= 0; i--) {
            a[l1-i].setValue(s1[i] - '0');
        }
        for (int i = s2.length() - 1;s2[i]!='-'&& i>= 0; i--) {
            b[l2-i].setValue(s2[i] - '0');
        }
        Convolution(a, b, q+1);
        for(int i=0;i<len;i++)
        {
            ans[i]=(int) (a[i].real+0.5);
        }
        for(int j=0;j<=len;j++) {
            ans[j + 1] += ans[j] / 10;
            ans[j]=ans[j] % 10;
        }
        while (ans[len]==0)len--;
        if (fu) cout<<'-';
        for (int j = len; j >= 0; j--) cout <<  ans[j];
        cout<<"\n";
    }

    return 0;
}