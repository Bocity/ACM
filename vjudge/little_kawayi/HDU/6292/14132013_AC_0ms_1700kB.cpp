#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    int cnt = 1;
    while(T--) {
        cout << "Problem "<< 1000 + cnt << ":" << endl;
        int n, m, x, ans1 = 66000, ans2 = 66000;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> x;
            ans1 = min(ans1, x);
        }
        cout << "Shortest judge solution: " << ans1 << " bytes." << endl;
        cout << "Shortest team solution: ";
        for(int i = 0; i < m; i++) {
            cin >> x;
            ans2 = min(ans2, x);
        }
        if(m == 0) cout << "N/A bytes." << endl;
        else cout << ans2 << " bytes." << endl;
        cnt++;
    }
    return 0;
}