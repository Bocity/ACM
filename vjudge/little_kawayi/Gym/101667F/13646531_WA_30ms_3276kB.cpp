#include <bits/stdc++.h>
using namespace std;
vector<int> q;
int a[3][3];
void swp(){
    swap(a[1][1],a[2][2]);
}
void swd(){
    swap(a[1][2],a[2][1]);
}
void dfs(int &x,int &y,int nn, int pos){
    if (nn == 1){
       // cout << pos << endl;
        for(int &xx:q){
            if (xx == 0){
                swd();
            }
            if (xx == 1){
                
            }
            if (xx== 2){
                
            }
            if (xx == 3){
                swp();
            }
        }
        for(int i = 1; i <= 2; ++i){
            for(int j = 1; j <=2; ++j){
                if (pos == a[i][j]){
                    x += i;
                    y += j;
                    return ;
                }
            }
        }
        return ;
    } 
    int ii = 0;
    int tmp2 = pos;
    while (tmp2 - nn*nn > 0){
        tmp2 -= nn * nn;
        ii++;
    }
    int iii = ii;
    q.push_back(ii);
    //cout << ii <<  " " << nn << " " << x << " " << y << endl;
    if (ii == 0){
        dfs(x,y,nn/2 ,tmp2);
    }else if(ii == 1){
        y += nn;
        dfs(x,y,nn/2 ,tmp2);
    }else if(ii == 2){
        y +=  nn;
        x +=  nn;
        dfs(x,y,nn/2 ,tmp2);
    }else{
        x += nn;
       
        dfs(x,y,nn/2 ,tmp2);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    a[1][1] = 1;
    a[1][2] = 2;
    a[2][2] = 3;
    a[2][1] = 4;
    cin >> n >> m;
    int nn = n;
    int x = 0,y = 0;
    dfs(x,y,nn/2,m);
    //cout << endl;
    cout << x << " "  << y << endl;
    return 0;
}