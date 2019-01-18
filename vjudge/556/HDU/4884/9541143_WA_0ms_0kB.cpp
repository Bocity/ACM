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
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int arr[2000][2];
void output(int t) {
    int hour = t / 60;
    t %= 60;
    cout << (hour < 10 ? "0" : "") << hour << ":" << (t < 10 ? "0" : "") << t << endl;
}
struct pii {
    int first, second, third;
};
queue<pii> q;
int main() {
    ios::sync_with_stdio(false);
    int t, num, temp, n, k, cas, m, id;
    int left;
    char ch;
    cin >> cas;
    while (cas--) {
        cin >> n >> t >> k >> m;
        while (!q.empty()) q.pop();
        REP(i, m) {
            left = 0;
            cin >> temp;
            left += temp * 60;
            cin >> ch;
            cin >> temp;
            left += temp;
            cin >> id >> num;
            q.push(pii{id, num, left});
        }
        mems(arr, 0);
        int more;
        int bias = 0, pre = 0;
        while (!q.empty()) {
            pii temp = q.front();
            q.pop();
            if (arr[temp.first][1] < temp.third) arr[temp.first][0] = 0;
            temp.third = max(bias, temp.third);
            more = 0;
            if (arr[temp.first][0] >= temp.second) {
                arr[temp.first][0] -= temp.second;
            } else if (arr[temp.first][0]) {
                more = (temp.second - arr[temp.first][0] + k - 1) / k;
                temp.third += t * more;
                arr[temp.first][0] = more * k - temp.second - arr[temp.first][0];
            } else {
                more = (temp.second + k - 1) / k;
                arr[temp.first][0] = more * k - temp.second;
                temp.third += t * more;
            }
            if (more) arr[temp.first][1] = bias + (more - 1) * t;
            output(temp.third);
            bias = temp.third;
        }
        if (cas) cout << endl;
    }
    return 0;
}