#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const int INF = 0x3f3f3f3f;
string gen;
int mp[4][3][N];
map<string, int> mpp;
void fuck() {
    for (int i = 4; i >= 0; i--) {
        gen[i]++;
        if (gen[i] > '9')
            gen[i] = '0';
        else
            return;
    }
}
int getSwap(string str) {
    if (mpp.count(str)) return mpp[str];
    int ret = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (str[j] < str[i]) ret++;
        }
    }
    return mpp[str] = ret;
}
inline int gan(string str) {
    int ret = 0;
    for (int i = 0; i < str.size(); i++) {
        ret *= 10;
        ret += str[i] - '0';
    }
    return ret;
}
int dfs(string pos, int op1, int op2) {
    int posNum = gan(pos);
    if (mp[op1][op2][posNum] != -1) return mp[op1][op2][posNum];

    int cnt[5];
    memset(cnt, 0, sizeof cnt);
    bool fg = true;
    for (int i = 0; i < 5; i++) {
        if (pos[i] > '5' || pos[i] < '1') {
            fg = false;
            break;
        }
        cnt[pos[i] - '1']++;
    }
    int ans = INF;
    if (fg) {
        sort(cnt, cnt + 5);
        // if (cnt[4] == 1) return mp[op1][op2][pos] = getSwap(pos);
        if (cnt[4] == 1) ans = getSwap(pos);
    }
    if (op1 == 3 && op2 == 2) return mp[op1][op2][posNum] = ans == INF ? -1 : ans;

    string now;
    if (op1 < 3) {
        for (int i = 0; i < 5; i++) {
            now = pos;
            now[i]--;
            if (now[i] < '0') now[i] += 10;
            int temp = dfs(now, op1 + 1, op2);
            if (temp != -1) ans = min(temp + 1, ans);
        }
    }
    if (op2 < 2) {
        for (int i = 0; i < 5; i++) {
            now = pos;
            if ((now[i] - '0') % 2 != 0) continue;

            now[i] = (now[i] - '0') / 2 + '5';
            int temp = dfs(now, op1, op2 + 1);
            if (temp != -1) ans = min(temp + 1, ans);

            now = pos;
            now[i] = (now[i] - '0') / 2 + '0';
            temp = dfs(now, op1, op2 + 1);
            if (temp != -1) ans = min(temp + 1, ans);
        }
    }
    return mp[op1][op2][posNum] = ans;
}

void init() {
    gen = "00000";
    memset(mp, -1, sizeof mp);
    for (int i = 0; i < 100000; i++) {
        // cout << dfs(gen, 0, 0) << endl;
        dfs(gen, 0, 0);
        fuck();
    }
}
int main() {
    ios::sync_with_stdio(false);
    // freopen("fuck2", "w", stdout);
    int t, m;
    string n;
    init();
    while (cin >> n) {
        int nn = gan(n);
        cout << (mp[0][0][nn] == INF ? -1 : mp[0][0][nn]) << endl;
    }
}