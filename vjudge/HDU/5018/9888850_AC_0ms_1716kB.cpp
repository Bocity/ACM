#include <bits/stdc++.h>
using namespace std;
int T;
long long a,b,c;
long long f[200];
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--){
        cin >> a >> b >> c;
        f[1]=a;
        f[2]=b;
        for(int i=3;i<100;i++){
            f[i]=f[i-1]+f[i-2];
            if (f[i]==c||f[i-1]==c||f[i-2]==c){
                cout<<"Yes\n";
                break;
            }
            if (f[i]>c){
                cout<<"No\n";
                break;
            }
        }
        
    }
    return 0;
}