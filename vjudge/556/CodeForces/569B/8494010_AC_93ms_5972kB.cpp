#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <climits>
#include <cmath>
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int a[100005];
int b[100005];
set<int> st;
int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
        st.erase(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if(b[a[i]] > 1 || a[i] > n) {
            b[a[i]]--;
            a[i] = *st.begin();
            st.erase(*st.begin());
        }
    }
    cout << a[1];
    for (int i = 2; i <= n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}