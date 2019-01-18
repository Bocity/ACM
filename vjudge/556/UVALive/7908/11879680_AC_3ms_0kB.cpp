#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int aa, bb, cc, dd;
int ans;
void dfs(int op) {
    if (op == 1) {
        a += 3;
        dfs(op + 1);
        a -= 3;

        b += 3;
        dfs(op + 1);
        b -= 3;

        a += 1;
        b += 1;

        dfs(op + 1);

        a -= 1;
        b -= 1;
    }
    if (op == 2) {
        a += 3;
        dfs(op + 1);
        a -= 3;

        c += 3;
        dfs(op + 1);
        c -= 3;

        a += 1;
        c += 1;

        dfs(op + 1);

        a -= 1;
        c -= 1;
    }
    if (op == 3) {
        a += 3;
        dfs(op + 1);
        a -= 3;

        d += 3;
        dfs(op + 1);
        d -= 3;

        a += 1;
        d += 1;

        dfs(op + 1);

        a -= 1;
        d -= 1;
    }
    if (op == 4) {
        b += 3;
        dfs(op + 1);
        b -= 3;

        c += 3;
        dfs(op + 1);
        c -= 3;

        b += 1;
        c += 1;

        dfs(op + 1);

        c -= 1;
        b -= 1;
    }
    if (op == 5) {
        b += 3;
        dfs(op + 1);
        b -= 3;

        d += 3;
        dfs(op + 1);
        d -= 3;

        d += 1;
        b += 1;

        dfs(op + 1);

        d -= 1;
        b -= 1;
    }
    if (op == 6) {
        c += 3;
        dfs(op + 1);
        c -= 3;

        d += 3;
        dfs(op + 1);
        d -= 3;

        c += 1;
        d += 1;

        dfs(op + 1);

        c -= 1;
        d -= 1;
    }
    if (op == 7) {
        if (aa == a && bb == b && cc == c && dd == d) ans++;
    }
}
int main() {
    int t, n, cnum = 1;
    cin >> t;
    while (t--) {
        cin >> aa >> bb >> cc >> dd;
        a = b = c = d = ans = 0;
        dfs(1);
        cout << "Case #" << cnum++ << ": ";
        if (ans == 0)
            cout << "Wrong Scoreboard" << endl;
        else if (ans == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}