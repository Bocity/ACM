#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;

int main(){
    int n,m,num,fro,cot;
    char op;
    while(~scanf("%d",&n)){
        fro = INF,cot = 0;
        for(int i = 1;i <= n;i++){
            scanf(" %c",&op);
            if(op == 'C'||op == 'B'){
                scanf("%d",&num);
                if(num <= fro){
                    cot++;
                    fro = num;
                }
                else fro = num;
            }
            else{
                cot++,fro = INF;
            }
        }
        printf("%d\n",cot);
    }
    return 0;
}
