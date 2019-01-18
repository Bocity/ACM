#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll a,b,c,T,z,p,x,y,ans,n;
pii q[1010];
map <pii,int> qqq;
int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin>>n;
        qq.clear();
        qqq.clear();
        for(int i=1;i<=n;i++){
            cin>> q[i].first>>q[i].second;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ll dx = q[i].first- q[j].first;
                ll dy = q[i].second- q[j].second;
                pii s;
                s.first= dx/__gcd (dx,dy);
                s.second= dy/__gcd(dx,dy);
                qqq[s]++;
        }
       }
        ans=0;
        for (map<pii, ll>::iterator i=qqq.begin(); i!=qqq.end(); i++)  
        {  
            ans+=((sqrt((i->second)*2.0)+1)-2)*(i->second)*1.0/3;
        }  

        cout<<ans<<endl;
    }
    return 0;
}