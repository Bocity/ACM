#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int a,b,c,T,z,p,x,y,n;
ll ans;
pii q[1010];

map <pii,int> qqq;
int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin>>n;
        qqq.clear();
        for(int i=1;i<=n;i++){
            cin>> q[i].first>>q[i].second;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int dx = q[i].first- q[j].first;
                int dy = q[i].second- q[j].second;
                if (dx<0){
                    dx=-dx;
                    dy=-dy;
                }
                pii s;
                s.first= dx/__gcd (dx,dy);
                s.second= dy/__gcd(dx,dy);
                qqq[s]++;
        }
       }
        ans=0;
        for (map<pii, int>::iterator i=qqq.begin(); i!=qqq.end(); i++)  
        {  
            ans+=((sqrt((i->second)*2.0)+1)-2)*(i->second)*1.0/3;
        }  

        cout<<ans<<endl;
    }
    return 0;
}