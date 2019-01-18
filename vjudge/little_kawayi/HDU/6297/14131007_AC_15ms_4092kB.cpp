#include <bits/stdc++.h>
#define REP(i,x,n) for(int i= x;i < n; ++i)
#define endl "\n"
#define maxn  10005
using namespace std;
struct node{
    string rank;
    string name;
    string pro;
    string status;
    int fuck;
}f[maxn];
//stirng ss;
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int k = 0;
    string s;
    getline(cin,s);
    REP(i,0,n){;
        getline(cin,s);
        //cout << s;
        stringstream mys(s);
        if (s.find("Running")!=string::npos){
            mys >> f[i].rank >> f[i].name >> f[i].pro >> f[i].status >> f[i].fuck;
            k = 3-f[i].rank.size();
            REP(j,0,k){
                cout << " ";
            }
            cout << f[i].rank << "|";
            cout << f[i].name ;
            k = 16 - f[i].name.size();
            REP(j,0,k){
                cout << " ";
            }
            cout << "|";
            cout << f[i].pro << "|[";
            REP(j,0,f[i].fuck){
                cout << "X";
            }
            REP(j,0,10-f[i].fuck){
                cout << " ";
            }
            cout << "]" << endl;

        }else{
            mys >> f[i].rank >> f[i].name >> f[i].pro >> f[i].status;
             k = 3-f[i].rank.size();
            REP(j,0,k){
                cout << " ";
            }
            cout << f[i].rank << "|";
            cout << f[i].name ;
            k = 16 - f[i].name.size();
            REP(j,0,k){
                cout << " ";
            }
            cout << "|";
            cout << f[i].pro << "|[";
            REP(j,0,4){
                cout << " ";
            }
            if (f[i].status == "FB"){
                cout << "AC*   ]" << endl;
            }else{
                if (f[i].status.size() ==  2){
                    cout << f[i].status << "    ]" << endl;
                }else{
                    cout << f[i].status << "   ]" << endl;
                }
            }
        }
        
    }
    return 0;
}