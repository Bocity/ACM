#include <bits/stdc++.h>
#define next asjifhjasiufhjsew
using namespace std;
const int maxn = 1e6+5;
int f[maxn];
int next[maxn];
void getnext(int len){      
    int i=0,j=-1;
    next[0]=-1;
    while(i<len){
        if(j==-1 || f[i]==f[j]){
            i++;j++;
            next[i]=j;
        }else
            j=next[j];
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n; i ++){
        cin >> f[i];
    }
    reverse(f,f+n);
    getnext(n);
    int minx = maxn;
    int x,y;
    for(int i = 1;i <= n; ++i){
        int kp = i-next[i] + n-i;
        if(minx > kp){
            x = n-i;
            y = i-f[i];
            minx = kp;
        }
    }
    cout << x << " "  << y << endl;
    return 0;
}