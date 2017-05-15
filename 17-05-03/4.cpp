#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll n, a[190000];
void sort1() {
    for (int i = 1; i <= n; i++) { //选择
        int p = i;
        for (int j = i + 1; j <= n; j++) {
            if (a[p] <= a[j]) {
                p = j;
            }
        }
        swap(a[i], a[p]);
    }
}
void sort2() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) { //插入
            if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);
        }
    }
}
void sort3() {
    //冒泡
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] < a[j]) swap(a[i], a[j]);
        }
    }
}
int vis[10000] = {0};
void prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            for (int j = i * 2; j <= n; j += i) {
                vis[j] = 1;
            }
        }
    }
}
void prime1(int x) {
    for (int i = 2; i <= x; i++) {       // 循环判断每个数是不是质数
        int flag = 0;                    //判断是否有大于1小于 i的约数
        for (int j = 2; j < i - 1; j++)  //循环判断
            if (i % j == 0) flag = 1;    //如果有记录
        if (flag == 0) cout << i << " "; //如果没有约数，就是素数
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort2();
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}