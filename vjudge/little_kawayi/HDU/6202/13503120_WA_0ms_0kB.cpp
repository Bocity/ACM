#include <bits/stdc++.h>
using namespace std;
int main(){
    int x = 332;
    while (x>0){
        cout <<((!(x % 2))?"YES":"NO" )<< endl;
        x/=2;
    }
    //cout << "NO" << endl;
    return 0;
}