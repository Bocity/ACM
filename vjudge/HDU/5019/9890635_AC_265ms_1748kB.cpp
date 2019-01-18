#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef long long ll;
ll a,b,c,T,z,p;
long long q[100000];
int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin>>a>>b>>c;
        int t = 0;
        z=__gcd(a,b);
        p=sqrt(z);
        for (int i=1;i<=p;i++){
            if (z%i==0){
                t++;
               q[t] = (ll)i;
               t++;
               q[t]=  (ll)z/i;
            }
        }
        sort(q+1,q+1+t);
        int pp ;
        pp = unique(q+1,q+1+t)-q-1;
        // for (int i=1;i<=pp;i++){
        //     cout << q[i]<<" ";
        // }
        if (c>pp) cout << "-1\n";
        else cout << q[pp-c+1]<<endl;
    }
    return 0;
}