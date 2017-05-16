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
int n;
int a[1000][1000] = {0};
void case1(int n, int x1, int y1, int x2, int y2, int k) {
    int x = x1, y = (y2 + y1) / 2, ans = k, sum = 1;
    while (sum++ <= n * n) {
        a[x][y] = ans++;
        if (a[x - 1][y + 1] && x - 1 >= x1 && y + 1 <= y2) {
            x++;
            continue;
        } else {
            if (x - 1 < x1 && y + 1 <= y2) {
                x = x2;
                y++;
                continue;
            }
            if (y + 1 > y2 && x - 1 >= x1) {
                y = y1;
                x--;
                continue;
            }
            if (y + 1 > y2 && x - 1 < x1) {
                x++;
                continue;
            }
        }
        x--;
        y++;
    }
    return;
}
void case2(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = ans++;
        }
    }
    for (int i = 1; i <= n; i += 4) {
        for (int j = 1; j <= n; j += 4) {
            a[i][j] = n * n - a[i][j] + 1;
            a[i + 3][j + 3] = n * n - a[i + 3][j + 3] + 1;
            a[i + 3][j] = n * n - a[i + 3][j] + 1;
            a[i][j + 3] = n * n - a[i][j + 3] + 1;
            a[i + 1][j + 1] = n * n - a[i + 1][j + 1] + 1;
            a[i + 2][j + 2] = n * n - a[i + 2][j + 2] + 1;
            a[i + 1][j + 2] = n * n - a[i + 1][j + 2] + 1;
            a[i + 2][j + 1] = n * n - a[i + 2][j + 1] + 1;
        }
    }
    return;
}
void case3(int n) {
    case1(n / 2, 1, 1, n / 2, n / 2, 1);
    case1(n / 2, n / 2 + 1, n / 2 + 1, n, n, n * n / 4 + 1);
    case1(n / 2, 1, n / 2 + 1, n / 2, n, n * n * 2 / 4 + 1);
    case1(n / 2, n / 2 + 1, 1, n, n / 2, n * n * 3 / 4 + 1);
    int k = (n - 2) / 4;
    for (int i = 1; i <= n / 2; i++) {
        if (i != (n + 2) / 4)
            for (int j = 1; j <= k; j++) {
                swap(a[i][j], a[i + n / 2][j]);
            }
        else {
            for (int j = i; j <= i + k - 1; j++) {
                swap(a[i][j], a[i + n / 2][j]);
            }
        }
    }
    for (int j = (1 + n / 2) / 2 + n / 2; j <= (1 + n / 2) / 2 + n / 2 + k - 2; j++)
        for (int i = 1; i <= n / 2; i++) {
            swap(a[i][j], a[i + n / 2][j]);
        }
}
void print(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%4d ", a[i][j]);
        }
        cout << endl;
    }
}
//幻方正确检查
bool Check(int n) {
    int sum = (n * (n * n + 1)) / 2;
    int SumA = 0, SumB = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) SumA += a[i][j];
        if (SumA != sum) return false;
        SumA = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) SumA += a[j][i];
        if (SumA != sum) return false;
        SumA = 0;
    }

    for (int i = 1; i <= n; i++) {
        SumA += a[i][i];
        SumB += a[i][n - i + 1];
    }
    if (SumA != sum || SumB != sum) return false;
    return true;
}
int main() {
    while (1) {
        cout << "任意阶幻方，输入0结束,请输入阶数：";
        cin >> n;
        if (n <= 0 || n == 2) return 0;
        mems(a, 0);
        if (n % 2) {
            case1(n, 1, 1, n, n, 1);
            print(n);
            cout << ((Check(n)) ? "yes" : "false");
        } else if (n % 4 == 0) {
            case2(n);
            print(n);
            cout << ((Check(n)) ? "yes" : "false");
        } else {
            case3(n);
            print(n);
            cout << ((Check(n)) ? "yes" : "false");
        }
    }
    return 0;
}