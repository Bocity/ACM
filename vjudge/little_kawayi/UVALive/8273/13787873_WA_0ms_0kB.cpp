#include <iostream>  
  
using namespace std;  
  
class Color  
{  
    friend int mColoring(int,int,int**);  
private:  
    bool OK(int);  
    void Trace(int);  
    int n;  
    int m;  
    int** a;  
    int* x;  
    long sum;  
};  
  
bool Color::OK(int k)  
{  
    for(int j = 1; j <= n; j++)  
        if( (a[k][j] == 1) && (x[j] == x[k]) )  return false;  
    return true;  
}  
  
void Color::Trace(int t)  
{  
    if (sum > 0) return ;
    if( t > n )  
    {  
        sum ++;  
    }  
    else{  
        for(int i = 1; i<= m; i++)  
        {  
            x[t] = i;  
            if( OK(t))  Trace(t+1);  
            x[t] = 0;  
        }  
    }  
}  
  
int mColoring(int n,int m,int** a)  
{  
    Color z;  
    z.n = n;  
    z.m = m;  
    z.a = a;  
    z.sum = 0;  
  
    int* p = new int[n+1];  
    for(int i = 0; i <= n; i++)  
        p[i] = 0;  
  
    z.x = p;  
  
    z.Trace(1);  
      
    delete []p;  
    return z.sum;  
}  
  
int main()  
{  
    int nodeNum,colorNum;  
    int t;
    cin >> t;
    while(t--){
        cin>>nodeNum; 
    
        int** mm = new int*[nodeNum+1];  
        for(int i = 1; i <= nodeNum; i++)  
        {  
            mm[i] = new int[nodeNum+1];  
 
        }  
        int p;
        cin >> p;
        for(int i = 0; i < p; ++i){
            int x,y;
            cin >> x >> y;
            x ++ ;
            y ++;
            mm[x][y] = 1;
            mm[y][x] = 1;
        }
        int dd = mColoring(nodeNum,3,mm);  
        if (dd > 0){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
        for(int i = 1; i <= nodeNum; i++)  
            delete []mm[i];  
        delete []mm;  
    }
    return 0;  
}  