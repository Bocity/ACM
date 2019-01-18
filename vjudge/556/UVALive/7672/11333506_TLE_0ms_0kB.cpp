#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const int INF = 0x3f3f3f3f;
string gen;
map<string, int> mp[4][3];
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
    int ret = 0;
    for (int i = 5; i > 0; i--) {
        char c = i + '0';
        for (int j = 0; j < 5; j++) {
            if (str[j] == c) {
                if (j != i - 1) {
                    swap(str[j], str[i - 1]);
                    ret++;
                    break;
                }
            }
        }
    }
    return ret;
}
int dfs(string pos, int op1, int op2) {
    if (mp[op1][op2].count(pos)) return mp[op1][op2][pos];

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
    if (fg) {
        sort(cnt, cnt + 5);
        if (cnt[4] == 1) return mp[op1][op2][pos] = op1 + op2 + getSwap(pos);
    }
    if (op1 == 3 && op2 == 2) return mp[op1][op2][pos] = -1;

    int ans = INF;
    if (op1 < 3) {
        for (int i = 0; i < 5; i++) {
            string now = pos;
            now[i]++;
            if (now[i] > '9') now[i] -= 10;
            int temp = dfs(now, op1 + 1, op2);
            if (temp != -1) ans = min(temp, ans);
        }
    }
    if (op2 < 2) {
        for (int i = 0; i < 5; i++) {
            string now = pos;
            now[i] += now[i] - '0';
            if (now[i] > '9') now[i] -= 10;
            int temp = dfs(now, op1, op2 + 1);
            if (temp != -1) ans = min(temp, ans);
        }
    }
    if (ans != INF)
        return mp[op1][op2][pos] = ans + op1 + op2;
    else
        return mp[op1][op2][pos] = -1;
}

void init() {
    gen = "00000";
    for (int i = 0; i < 100000; i++) {
        dfs(gen, 0, 0);
        fuck();
    }
}
int main() {
    ios::sync_with_stdio(false);
    int t, m;
    string n;
    // init();
    // cout << "FUCK" << endl;
    while (cin >> n) {
        dfs(n, 0, 0);
        cout << mp[0][0][n] << endl;
    }
}