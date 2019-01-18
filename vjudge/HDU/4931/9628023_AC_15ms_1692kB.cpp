#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[100];
int main(){
    int t;
    cin>>t;
    while(t--){
       for(int i=1;i<=6;i++){
           cin>>a[i];
       }
       sort(a+1,a+7);
       
           if (a[6]+a[5]>a[2]+a[3]+a[4]) cout<<"Grandpa Shawn is the Winner!"<<endl;
           else cout<<"What a sad story!"<<endl;
       
    }
    return 0;
}