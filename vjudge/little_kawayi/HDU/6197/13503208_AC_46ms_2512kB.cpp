#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
const int maxn = 100000 + 10;
int a[maxn], b[maxn], dp[maxn];
int LIS(int arr[], int n) {
    int lis = 1;
    dp[1] = arr[0];
    for(int i = 1; i < n; i++){
        int pos = upper_bound(dp + 1, dp + lis + 1, arr[i]) - dp;    
        dp[pos] = arr[i];
        lis = max(lis, pos);
    }
    return lis;
}        
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[n - i - 1] = a[i];
        }
        int len1 = LIS(a, n);
        int len2 = LIS(b, n);
        if((n - len1) <= k || (n - len2) <= k) cout << "A is a magic array." << endl;
        else cout << "A is not a magic array." << endl;
    }
    return 0;
}