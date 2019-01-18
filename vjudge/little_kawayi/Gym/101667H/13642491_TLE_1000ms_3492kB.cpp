#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = x; i < n; ++i)
using namespace std;
string s,s1;
bitset<100005>R,P,S,R1,P1,S1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    cin >> s >> s1;
    int p1 = s.size();
    REP(i,0,p1){
        if (s[i] == 'R')R.set(i);
        if (s[i] == 'P')P.set(i);
        if (s[i] == 'S')S.set(i);
    }
    int p2 = s1.size();
    REP(i,0,p2){
        if (s1[i] == 'R')R1.set(i);
        if (s1[i] == 'P')P1.set(i);
        if (s1[i] == 'S')S1.set(i);
    }
    int p3 = p2 - p3;
    int ans = 0;
    int anss = 0;
    ans += (R1 & (S)).count();
    ans += (S1 & (P)).count();
    ans += (P1 & (R)).count();
    anss = max(anss,ans);
    for(int i = 0; i < p1 - anss; ++i){
        ans = 0;
        R1 <<= 1;
        P1 <<= 1;
        S1 <<= 1;
        ans += (R1 & (S)).count();
        ans += (S1 & (P)).count();
        ans += (P1 & (R)).count();
        anss = max(anss,ans);
    }
    cout << anss << endl;
    return 0;
}