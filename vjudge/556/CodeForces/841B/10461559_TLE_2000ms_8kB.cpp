#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, flag = 0;
    cin >> n;
    while (cin >> n) flag |= n & 1;
    puts(flag ? "First" : "Second");
}