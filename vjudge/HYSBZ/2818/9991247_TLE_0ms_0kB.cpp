#include <bitset>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long LL;
const int N = 10000010;

bitset<N> prime;
LL phi[N];
LL f[N];
int p[N];
int k;

void isprime() {
    k = 0;
    prime.set();
    for (int i = 2; i < N; i++) {
        if (prime[i]) {
            p[k++] = i;
            for (int j = i + i; j < N; j += i) prime[j] = false;
        }
    }
}

void Init() {
    for (int i = 1; i < N; i++) phi[i] = i;
    for (int i = 2; i < N; i += 2) phi[i] >>= 1;
    for (int i = 3; i < N; i += 2) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i) phi[j] = phi[j] - phi[j] / i;
        }
    }
    f[1] = 0;
    for (int i = 2; i < N; i++) f[i] = f[i - 1] + (phi[i] << 1);
}

LL Solve(int n) {
    LL ans = 0;
    for (int i = 0; i < k && p[i] <= n; i++) ans += 1 + f[n / p[i]];
    return ans;
}

int main() {
    Init();
    isprime();
    int n;
    scanf("%d", &n);
    printf("%lld\n", Solve(n));
    return 0;
}