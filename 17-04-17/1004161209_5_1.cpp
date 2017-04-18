#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

class Fraction {
  public:
    Fraction();
    Fraction(int n);
    Fraction(int n, int d);
    void setValue(int n, int d);
    int getNum() {
        return num;
    }
    int getDen() {
        return den;
    }
    double getDoubleValue() {
        return (double) num / den;
    }
    void output() {
        if (num * den != 0) {
            cout << "分数形式 "
                 << " 分子:" << num << " 分母:" << den << " 输出结果:";
        } else {
            cout << "分数形式 "
                 << " 分子:" << 0 << " 分母:"
                 << "任意"
                 << " 输出结果:";
        }

        if (num * den == 0) {
            cout << 0 << endl;
            return;
        }
        if (num * den < 0) cout << "-";
        if (abs(num) % abs(den) == 0)
            cout << abs(num) / abs(den) << endl;
        else {
            if (abs(num) > abs(den)) cout << abs(num / den) << " ";
            cout << abs(num % den) << "/" << abs(den) << endl;
        }
    }
    Fraction operator+(const Fraction &b) const {
        Fraction f1 = *this;
        Fraction f2;
        ll a = b.num, e = b.den, c = f1.num, d = f1.den;
        f2.den = e * d;
        f2.num = a * d + e * c;
        f2.normalize();
        return f2;
    }
    Fraction operator-(const Fraction &b) const {
        Fraction f1 = *this;
        Fraction f2;
        ll a = b.num, e = b.den, c = f1.num, d = f1.den;
        f2.den = e * d;
        f2.num = -a * d + e * c;
        f2.normalize();
        return f2;
    }
    Fraction operator*(const Fraction &b) const {
        Fraction f1 = *this;
        Fraction f2;
        ll a = b.num, e = b.den, c = f1.num, d = f1.den;
        f2.den = e * d;
        f2.num = a * c;
        f2.normalize();
        return f2;
    }
    Fraction operator/(const Fraction &b) const {
        Fraction f1 = *this;
        Fraction f2;
        ll a = b.num, e = b.den, c = f1.num, d = f1.den;
        f2.den = d * a;
        f2.num = e * c;
        f2.normalize();
        return f2;
    }

  private:
    int num;
    int den;
    void normalize() {
        if (den == 0) {
            den = 1;
            return;
        }
        if (den * num < 0) {
            den = abs(den);
            num = -abs(num);
        } else {
            den = abs(den);
            num = abs(num);
        }
        ll xx = __gcd(num, den);
        num = num / xx;
        den = den / xx;
        return;
    }
};
void Fraction::setValue(int n, int d) {
    num = n;
    den = d;
    this->normalize();
}
Fraction::Fraction(int n) {
    num = n;
    den = 1;
}
Fraction::Fraction() {
    num = 0;
    den = 1;
}
Fraction::Fraction(int n, int d) {
    if (den == 0) {
        num = 1;
        den = 1;
    }
    num = n;
    den = d;
}

int main() {
    Fraction f1, f2(2), f3(3, 4);
    cout << "f1";
    f1.output();
    cout << "f2";
    f2.output();
    cout << "f3";
    f3.output();
    f1.setValue(6, 4);
    cout << "f1";
    f1.output();
    cout << "f2+f3:";
    (f2 + f3).output();
    cout << "double value of f2+f3: " << f2.getDoubleValue() + f3.getDoubleValue() << endl;
    cout << "f2-f3:";
    (f2 - f3).output();
    cout << "double value of f2-f3: " << f2.getDoubleValue() - f3.getDoubleValue() << endl;
    cout << "f2*f3:";
    (f2 * f3).output();
    cout << "double value of f2*f3: " << f2.getDoubleValue() * f3.getDoubleValue() << endl;
    cout << "f2/f3:";
    (f2 / f3).output();
    cout << "double value of f2/f3: " << f2.getDoubleValue() / f3.getDoubleValue() << endl;
    cout << "double value of f1:" << f1.getDoubleValue() << endl;
}