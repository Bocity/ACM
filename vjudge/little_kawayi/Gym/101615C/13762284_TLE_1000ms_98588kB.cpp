#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
#define base (int) 1e9
using namespace std;
class BigInteger {
  private:
    vector<int> Integer;
    void SetInteger() {
        while (this->Integer.size() > 1 && this->Integer.back() == 0) {
            this->Integer.pop_back();
        }
    }
    void print() {
        SetInteger();
        printf("%d", this->Integer.size() == 0 ? 0 : this->Integer.back());
        int len = this->Integer.size() - 2;
        for (int i = len; i >= 0; i--) {
            printf("%09d", this->Integer[i]);
        }
    }

  public:
    BigInteger() {}
    // 使用string初始化BigInteger，不支持负数
    BigInteger(string s) {
        if (s.size() == 0) {
            Integer.push_back(0);
            return;
        }
        while (s.size() % 9 != 0) {
            s = '0' + s;
        }
        int len = s.size();
        for (int i = 0; i < len; i += 9) {
            int v = 0;
            for (int j = i; j < i + 9; j++) v = v * 10 + (s[j] - '0');
            Integer.insert(Integer.begin(), v);
        }
    }
    // 使用char 数组初始化 BigInteger
    BigInteger(char c[]) {
        string s = c;
        new (this) BigInteger(s);
    }
    //使用 long long 类型初始化 BigInteger
    BigInteger(long long x) {
        string s = "";
        while (x > 0) {
            s = char(x % 10 + '0') + s;
            x /= 10;
        }
        new (this) BigInteger(s);
    }
    // 使用int类型初始化 BigInteger
    BigInteger(int x) {
        new (this) BigInteger((long long) x);
    }
    //重载输入运算符
    friend istream &operator>>(istream &in, BigInteger &a) {
        string s;
        cin >> s;
        BigInteger temp(s);
        a = temp;
        return in;
    }
    //重载输出运算符
    friend ostream &operator<<(ostream &out, BigInteger a) {
        a.print();
        return out;
    }
    // 重载=运算符
    BigInteger &operator=(const BigInteger &a) {
        this->Integer = a.Integer;
        return *this;
    }
    //重载<运算符，用于两个大数之间的比较
    friend bool operator<(BigInteger a, BigInteger b) {
        a.SetInteger();
        b.SetInteger();
        if (a.Integer.size() != b.Integer.size()) return a.Integer.size() < b.Integer.size();
        int len = a.Integer.size() - 1;
        for (int i = len; i >= 0; i--) {
            if (a.Integer[i] != b.Integer[i]) return a.Integer[i] < b.Integer[i];
        }
        return false;
    }
    //重载<运算符，可以用于任意类型的比较
    template <typename T> friend bool operator<(BigInteger a, T b) {
        BigInteger t((long long) b);
        return a < t;
    }

    //重载>运算符，用于两个大数之间的比较
    friend bool operator>(BigInteger a, BigInteger b) {
        return b < a;
    }
    // 重载>运算符，可以用于任意类型的比较
    template <typename T> friend bool operator>(BigInteger a, T b) {
        BigInteger t((long long) b);
        return t < a;
    }
    //重载==运算符
    friend bool operator==(BigInteger a, BigInteger b) {
        return !(a < b) && !(b < a);
    }
    // 重载！=运算符
    friend bool operator!=(BigInteger a, BigInteger b) {
        return !(a == b);
    }
    //重载==运算符，可以用于任意类型的比较
    template <typename T> friend bool operator==(BigInteger a, T b) {
        BigInteger t((long long) b);
        return !(a < t) && !(t < a);
    }
    // 重载<=运算符，可以用于任意类型的比较
    template <typename T> friend bool operator<=(BigInteger a, T b) {
        return a < b || a == b;
    }
    // 重载>=运算符，可以用于任意类型的比较
    template <typename T> friend bool operator>=(BigInteger a, T b) {
        return b < a || b == a;
    }
    //重载+运算符，用于两个大数相加
    BigInteger operator+(BigInteger x) {
        BigInteger y = *this, ans;
        x.SetInteger();
        y.SetInteger();
        int carry = 0;
        int len = max(x.Integer.size(), y.Integer.size());
        for (int i = 0; i < len; i++) {
            if (i < (int) x.Integer.size()) carry += x.Integer[i];
            if (i < (int) y.Integer.size()) carry += y.Integer[i];
            ans.Integer.push_back(carry % base);
            carry /= base;
        }
        if (carry) ans.Integer.push_back(carry);
        ans.SetInteger();
        return ans;
    }
    //重载+运算符，用于大数和任意类型相加
    template <typename T> BigInteger operator+(T x) {
        BigInteger t((long long) x);
        return *this + t;
    }
    //重载后置++运算符
    const BigInteger operator++(int) {
        BigInteger t = *this;
        *this = *this + 1;
        return t;
    }
    //重载前置++运算符
    BigInteger &operator++() {
        *this = *this + 1;
        return *this;
    }
    //重载+=运算符，用于两个大数相加
    BigInteger &operator+=(BigInteger x) {
        *this = *this + x;
        return *this;
    }
    //重载+=运算符，用于任意类型相加
    template <typename T> BigInteger &operator+=(T x) {
        BigInteger t((long long) x);
        *this = *this + t;
        return *this;
    }
    //重载-运算符，用于两个大数相减
    BigInteger operator-(BigInteger x) {
        BigInteger y = *this, ans;
        x.SetInteger();
        y.SetInteger();
        int carry = 0, len = y.Integer.size();
        for (int i = 0; i < len; i++) {
            carry += y.Integer[i] - (i < (int) x.Integer.size() ? x.Integer[i] : 0);
            if (carry < 0) {
                ans.Integer.push_back(carry + base);
                carry = -1;
            } else {
                ans.Integer.push_back(carry);
                carry = 0;
            }
        }
        ans.SetInteger();
        return ans;
    }
    //重载-运算符，用于大数与任意类型相减
    template <typename T> BigInteger operator-(T x) {
        BigInteger t((long long) x);
        return *this - t;
    }
    //重载后置--运算符
    const BigInteger operator--(int) {
        BigInteger t = *this;
        *this = *this - 1;
        return t;
    }
    //重载前置--运算符
    BigInteger &operator--() {
        *this = *this - 1;
        return *this;
    }
    //重载-=运算符，用于两个大数相减
    BigInteger &operator-=(BigInteger x) {
        *this = *this - x;
        return *this;
    }
    //重载-=运算符，用于大数和任意类型相减
    template <typename T> BigInteger &operator-=(T x) {
        BigInteger t((long long) x);
        *this = *this - t;
        return *this;
    }
    //重载*运算符，用于两个两个大数相乘
    BigInteger operator*(BigInteger x) {
        BigInteger y = *this, ans;
        x.SetInteger();
        y.SetInteger();
        int xlen = x.Integer.size(), ylen = y.Integer.size();
        ans.Integer.assign(xlen + ylen, 0);
        for (int i = 0; i < xlen; i++) {
            long long carry = 0ll;
            for (int j = 0; j < ylen || carry > 0; j++) {
                long long s =
                    ans.Integer[i + j] + carry + (long long) x.Integer[i] * (j < (int) y.Integer.size() ? (long long) y.Integer[j] : 0ll);
                ans.Integer[i + j] = s % base;
                carry = s / base;
            }
        }
        ans.SetInteger();
        return ans;
    }
    //  重载 *运算符, 用于大数和任意两个数相乘
    template <typename T> BigInteger operator*(T x) {
        BigInteger t((long long) x);
        return *this * t;
    }
    // 重载*= 算符,      用于两个大数相乘
    BigInteger &operator*=(BigInteger x) {
        *this = *this * x;
        return *this;
    }
    // 重载*=运算符, 用于大数与任意类型的数相乘
    template <typename T> BigInteger &operator*=(T x) {
        BigInteger t((long long) x);
        *this = *this * t;
        return *this;
    }
    // 重载 / 运算符, 用于两个大数相除
    BigInteger operator/(BigInteger x) {
        BigInteger y = *this, ans, cur;
        x.SetInteger();
        y.SetInteger();
        int len = y.Integer.size() - 1;
        for (int i = len; i >= 0; i--) {
            cur.Integer.insert(cur.Integer.begin(), y.Integer[i]);
            int t = 0, l = 0, r = base;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (x * BigInteger(mid) > cur) {
                    t = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            cur = cur - BigInteger(t - 1) * x;
            ans.Integer.insert(ans.Integer.begin(), t - 1);
        }
        ans.SetInteger();
        return ans;
    }
    // 重载/运算符, 用于大数和任意类型相除
    template <typename T> BigInteger operator/(T x) {
        BigInteger y = *this, ans, t((long long) x);
        y.SetInteger();
        long long cur = 0ll;
        int len = y.Integer.size() - 1;
        for (int i = len; i >= 0; i--) {
            cur = cur * (long long) base + (long long) y.Integer[i];
            ans.Integer.insert(ans.Integer.begin(), cur / x);
            cur %= x;
        }
        ans.SetInteger();
        return ans;
    }
    //  重载 /=运算符,  用于大数和大数相除
    BigInteger &operator/=(BigInteger x) {
        *this = *this / x;
        return *this;
    }
    //重载 /=运算符,  用于大数和任意类型相除
    template <typename T> BigInteger &operator/=(T x) {
        BigInteger t((long long) x);
        *this = *this / t;
        return *this;
    }
    //重载%运算符，用于两个大数之间的取余数操作
    BigInteger operator%(BigInteger x) {
        BigInteger y = *this, ans;
        x.SetInteger();
        y.SetInteger();
        int len = y.Integer.size() - 1;
        for (int i = len; i >= 0; i--) {
            ans.Integer.insert(ans.Integer.begin(), y.Integer[i]);
            int t = 0, l = 0, r = base;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (x * BigInteger(mid) > ans) {
                    t = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            ans = ans - BigInteger(t - 1) * x;
        }
        ans.SetInteger();
        return ans;
    }
    //  重载 % 算符, 用于大数和任意类型的数
    template <typename T> T operator%(T x) {
        BigInteger y = *this;
        y.SetInteger();
        T ans = (T) 0;
        int len = y.Integer.size() - 1;
        for (int i = len; i >= 0; i--) {
            ans = (ans * (base % x) + y.Integer[i] % x) % x;
        }
        return ans;
    }
    //  重载%= 算符, 大数之间
    BigInteger &operator%=(BigInteger x) {
        *this = *this % x;
        return *this;
    }
    // 重载%=运算符     大数和任意类型
    template <typename T> BigInteger &operator%=(T x) {
        BigInteger t((long long) x);
        *this = *this % t;
        return *this;
    }
    friend BigInteger power(BigInteger a, BigInteger x) {
        if (x == BigInteger(0) || a == BigInteger(1)) return BigInteger(1);
        BigInteger tmp = power(a, x / 2);
        if (x % 2 == 0) return tmp * tmp;
        return tmp * tmp * a;
    }
    // 大数和较小数
    template <typename T> friend BigInteger power(BigInteger a, T x) {
        return power(a, BigInteger((long long) x));
    }
    // 大数和大数
    friend BigInteger gcd(BigInteger a, BigInteger b) {
        a.SetInteger();
        b.SetInteger();
        while (b > BigInteger(0)) {
            BigInteger r = a % b;
            a = b;
            b = r;
        }
        a.SetInteger();
        return a;
    }
    //  最小公倍数
    friend BigInteger lcm(BigInteger a, BigInteger b) {
        return a * b / gcd(a, b);
    }
    // 大数开方
    friend BigInteger sqrt(BigInteger a) {
        BigInteger x0 = a, x1 = (a + 1) / 2;
        while (x1 < x0) {
            x0 = x1;
            x1 = (x1 + a / x1) / 2;
        }
        return x0;
    }
    //  大数 log
    friend int log(BigInteger a, int n) { // log_n(a)
        int ans = 0;
        a.SetInteger();
        while (a > BigInteger(1)) {
            ans++;
            a /= n;
        }
        return ans;
    }
};
typedef unsigned long long ll;
__gnu_pbds::cc_hash_table<ll, bool> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
const int maxn = 10005;
ll n, m, k;
const long long mod = 1000000007;
BigInteger ans = 0;
vector <ll> q;
main() {
    ll a,b;
    cin >> a >> b ;
    ll p = sqrt(b) + 0.5;
    q.clear();
    REP(i,1,p+1){
        if (!hash1[i])
        q.push_back(i);
        hash1[i] = true;
        if (!hash1[b/i])
        q.push_back(b/i);
        hash1[b/i] = true;
    }
    for(auto &i:q){
        ll l = b/ (i + 1) + 1, r = b / i;
        ans += i * (r - l + 1) * (l + r) / 2;
    }
    //cout << ans << endl;
    a--;
    q.clear();
    hash1.clear();
    p = sqrt(a) + 0.5;
    REP(i,1,p+1){
        if (!hash1[i])
        q.push_back(i);
        hash1[i] = true;
        if (!hash1[a/i])
        q.push_back(a/i);
        hash1[a/i] = true;
    }
    for(auto &i:q){
        ll l = a / (i + 1) + 1, r = a / i;
        ans -= i * (r - l + 1) * (l + r) / 2;
    }
    cout << ans << endl ;
    return 0;
}