#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
  
#define M 26  
  
int n, ans, color[M];   
bool map[M][M], isFind;  
  
inline bool ok(int x, int c) {   //判断是否存在相邻节点颜色相同  
     for (int i = 0; i < n; i++)  
        if (map[x][i] && c == color[i])  
            return false;  
     return true;  
}  
  
void DFS(int id, int total) {   //当前搜索到下标为id的节点，此时总共用的色彩数为total  
     if (isFind) return;  
     if (id >= n) { isFind = true; return; }  //当所有节点都被着色后，返回  
     if (ans > 3) return ;
     for (int i = 1; i <= total; i++) {  
         if (ok(id, i)) {  
            color[id] = i;  
            DFS(id+1, total); 
            if (ans > 3) return  ;
            color[id] = 0;  
         }  
     }  
     if (!isFind) {    //当用total种颜色无法完成时，则增加一种颜色进行着色  
        ans++;  
        if (ans > 3) return ;
        DFS(id, total+1);  
     }  
}  

int main()  
{  
    int t;
    cin >> t;
    while(t--)  
    {  
        cin>>n;
        memset (map, false, sizeof (map));  
        memset (color, 0, sizeof (color));  
        int p = 0;
        cin >>p;
        for(int i = 0 ; i < p; ++ i){
            int xx,yy;
            cin >> xx >> yy;
            map[xx][yy] = 1;
            map[yy][xx] = 1;

        }
        isFind = false;  
        ans = 1;  
        DFS(0, 1);  
        if(ans<=3)  
        {  
            cout<<"Y"<<endl;  
        }  
        else  
        {  
            cout<<"N"<<endl;  
        }  
    }  
} 