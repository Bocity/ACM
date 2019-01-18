#include <iostream>
#include <string>
using namespace std;
string s[1000];
int n,ans;
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int casee=1;casee<=T;casee++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        bool flag=false;
        for(int i=1;i<=n-1;i++){
            if (s[i+1].find(s[i])==string::npos){
                flag=true;
                for(int j=n;j>=i;j--){
                    if (s[j].find(s[i])==string::npos)
                    {
                        ans=j;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        cout<<"Case #"<<casee<<": ";
        if (!flag){
                cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}