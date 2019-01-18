#include <bits/stdc++.h>
using namespace std;
int main(){
cin.tie(0);
int n,m;
while(cin >> n>>m){
int g = __gcd(n*m,n+m);
cout << n*m/g<<"/"<<(n+m)/g<<endl;
}
return 0;
}