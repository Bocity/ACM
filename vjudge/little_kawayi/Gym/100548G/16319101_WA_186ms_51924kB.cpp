#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n) - 1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7;
// const int maxn = 100000 + 10;
const int maxn = 400000 + 10;
const int N = 26;
char s[maxn];
struct PalindromicTree {
    int Next[maxn][N];//next指针和字典数类似，指向的串为当前串两端加同一个字符构成的串
    int fail[maxn];
    int cnt[maxn];//结点i代表的字符串在原串中出现的次数，建树时不准确，建树完成后重新用count()计算
    int cnt2[maxn];//结点i代表的字符串在原串中出现的次数，建树时不准确，建树完成后重新用count()计算
    int num[maxn];//最长回文串的最右端点为i回文串结尾的回文串个数
    int len[maxn];//结点i表示的回文串的长度
    int str[maxn];//添加的字符
    int last;//指向上一个字符所在的结点
    int n;//添加的字符的个数
    int p;//添加的结点的个数
    //新建结点
    int newNode(int l) {
        for(int i = 0; i < N; i++) Next[p][i] = 0;
        cnt[p] = 0;
        cnt2[p] = 0;
        num[p] = 0;
        len[p] = l;
        return p++;
    }
    //初始化
    void init() {
        p = 0;
        newNode(0);
        newNode(-1);
        last = 0;
        n = 0;
        str[n] = -1;
        fail[0] = 1;
    }
    void init2() {
        last = 0;
        n = 0;
        str[n] = -1;
        fail[n] = 1;
    }
    int getFail(int x) {
        while(str[n - len[x] - 1] != str[n]) x = fail[x];
        return x;
    }
    //建树
    void add(char c) {
        c -= 'a';
        str[++n] = c;
        int cur = getFail(last);
        if(!Next[cur][c]) {
            int now = newNode(len[cur] + 2);
            fail[now] = Next[getFail(fail[cur])][c];
            Next[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = Next[cur][c];
        cnt[last]++;
        // return num[last];
    }
    void add2(char c) {
        c -= 'a';
        str[++n] = c;
        int cur = getFail(last);
        if(!Next[cur][c]) {
            int now = newNode(len[cur] + 2);
            fail[now] = Next[getFail(fail[cur])][c];
            Next[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = Next[cur][c];
        cnt2[last]++;
        // return num[last];
    }
    void count() {
        //父结点累加子结点的cnt: 如果fail[v] = u, 则u一定是v的子回文串
        for(int i = p - 1; i >= 0; i--) cnt[fail[i]] += cnt[i];
    }
    void count2() {
        //父结点累加子结点的cnt: 如果fail[v] = u, 则u一定是v的子回文串
        for(int i = p - 1; i >= 0; i--) cnt2[fail[i]] += cnt2[i];
    }
}tr;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    int numm = 1;
    while(T--) {
        string s1, s2;
        cin >> s1 >> s2;
        tr.init();
        for(int i = 0; i < s1.size(); i++) tr.add(s1[i]);
        tr.count();
        tr.init2();
        for(int i = 0; i < s2.size(); i++) tr.add2(s2[i]);
        tr.count2();
        ll ans = 0;
        for(int i = 2; i < tr.p; i++) {
            // cout << tr.cnt[i] << ' ' << tr.cnt2[i] << endl;
            ans += tr.cnt[i] * tr.cnt2[i];
        }
        cout << "Case #" << numm++ << ": " << ans << endl;
    }
    return 0;
}