#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
    for(int i = 1; i <= p1 - anss; ++i){
        ans = 0;
        S >>= i;
        P >>= i;
        R >>= i;
        ans += ((R1) & (S)).count();
        ans += ((S1) & (P)).count();
        ans += ((P1) & (R)).count();
        anss = max(anss,ans);
    }
    cout << anss << endl;
    return 0;
}