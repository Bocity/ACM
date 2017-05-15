#include <iostream>
using namespace std;
int main() {
    long long f[1000] = {0};
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 1000; i++) f[i] = f[i - 1] + f[i - 2];
    int n;
    cout << f[104];
    cin >> n;
    for (int i = 1; i <= 1000; i++)
        if (f[i] % n == 0) cout << i << " ";
}
/*
偶数 n%3==0
3的倍数 n%4==0
4的倍数 n%6==0
5的倍数 n%5==0
6的倍数 n%12==0
7的倍数 n%8==0
8的倍数 n%6==0
9的倍数 n%12==0
10的倍数 n%15==0
*/