#include <bits/stdc++.h>
using namespace std;
int main(){
    int x = 339;
    while (x>0){
        cout <<((!(x % 2))?"YES":"NO" )<< endl;
        x/=2;
    }
    //cout << "NO" << endl;
    return 0;
}