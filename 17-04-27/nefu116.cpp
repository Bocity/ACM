#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
void ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 1) {
        x = 1;
        y = 1 - a;
    } else {
        long long x1, y1;
        ex_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - x * (a / b);
    }
}
