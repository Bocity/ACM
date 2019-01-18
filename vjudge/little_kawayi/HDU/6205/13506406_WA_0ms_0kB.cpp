#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = x ; i < n; ++i)
using namespace std;
int a[1000005];
int b[1000005];
int c[1000005];
int main(){
    int n = 0;
    ios::sync_with_stdio(0);
    while(cin >> n){
        REP(i,0,n){
            cin >> a[i];
        }
        REP(i,0,n){
            cin >> b[i];
            c[i] = a[i] - b[i];
            //cout << c[i];
        }
        int ans3 = 0;
        int ans4 = 0;
        REP(i,0,n){
            if (c[i]>=0){
                int j = i;
                int ans = 0;
                int ans2 = 0;
                while(ans + c[j] >= 0){
                    ans += c[j];
                    ans2 += a[j];
                    j++;
                    if (j >= n){
                        j = 0;
                    }
                    if (j == i){
                        break;
                    }
                }
                if (ans2  >  ans3){
                    ans4 = i;
                    ans3 = ans2;
                }
                if (j < i) break;
                i = j + 1;

                //cout << i << endl;
            }
        }
        cout << ans4 << endl;
    }
    return 0;
}