#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
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
Complex a[20000000], f[2000000], A[2000000], B[2000000];
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
long long x, n;
void CDQ(ll l, ll r) {
    if (l == r) {
        f[l].real += a[l].real;
        f[l].real = (ll) f[l].real % MOD;
        return;
    }
    ll m = (l + r) >> 1;
    CDQ(l, m);
    for (int i = l; i <= m; i++) A[i - l].real = f[i].real;
    for (int i = 0; i <= r - l; i++) B[i].real = a[i + 1].real;
    Convolution(A, B, r - l + 1);
    for (int i = m + 1; i <= r; i++) {
        f[i].real += ((ll)(A[i - l - 1].real + 0.5)) % MOD;
        f[i].real = (ll) f[i].real % MOD;
    }
    CDQ(m + 1, r);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n && n != 0) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            cin >> x;
            x %= MOD;
            a[i].real = x;
        }
        CDQ(1, n);

        cout << (ll) f[n].real << "\n";
    }
    return 0;
}