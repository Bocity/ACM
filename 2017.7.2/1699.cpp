#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#define pi acos(-1.0)
#define endl "\n"
typedef long long ll;
using namespace std;
map<string, bool> q;
int main() {
    ll n;
    cin >> n;
    if (n == 0)
        cout << 1;
    else
        cout << 9 * n * n / 2 - 7 * n / 2 + 1;
    return 0;
}
