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
    const int maxn = 100000 + 10;

    int main() {
        unsigned long long  n;
        // print(mod);
        // cout<<endl;
        unsigned long long  a,b,c;
        while(cin >> a >> b >> c)
        {
            // scan(b);
            // scan(c);
            cin>>n;
            unsigned long long  k;
            if(a==b&&a==c)
            {k=1;}
            else
            if(a==b||a==c||b==c)
            {
                k=3;

            }else
                k=6;
            unsigned long long  ans1 = n,ans2 = n - 1, ans3 = n - 2;
            if(ans1 % 2 == 0) ans1 /= 2;
            else if(ans2 % 2 == 0) ans2 /= 2;
            else if(ans3 % 2 == 0) ans3 /= 2;
            if(ans1 % 3 == 0) ans1 /= 3;
            else if(ans2 % 3 == 0) ans2 /= 3;
            else if(ans3 % 3 == 0) ans3 /= 3;
            ull ans = ans1 * ans2 * ans3;
            unsigned long long  pos= ((n + 1) / 2 - 2) * ((n + 1) / 2 - 1) / 2;//n%2==0?n/2:n/2+1;
            //ans2 =  (( pos -1)*(pos-2))/2;
            pos*=n;
            //cout<<ans1<<" "<<ans2<<endl;
            // print(ans1);
            // cout << endl;
            // print(ans2);
            // cout << endl;
            cout<<(ans-pos)*k<<endl;
        }
        return 0;
    }