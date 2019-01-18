#include <bitset>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
bitset<1005> tmp,bit[10005];  
int main(){                                     //直接用bitset维护每一个数所在的集合  
    int n,m,q,u,v,i,j;                          //询问的时候直接两个集合相与判断是否  
    while(scanf("%d",&n)!=EOF){                 //存在  
        for(i=0;i<=10000;i++)  
        bit[i].reset();                         //也可用网上很普遍的做法，用32个整数去  
        for(i=1;i<=n;i++){                      //表示每一个数的状态，但是远没有bitset容易实现....  
            scanf("%d",&m);  
            while(m--){  
                scanf("%d",&u);  
                bit[u][i]=1;  
            }  
        }  
        scanf("%d",&q);  
        while(q--){  
            scanf("%d%d",&u,&v);  
            tmp=bit[u]&bit[v];  
            if(tmp.count()!=0)  
            puts("Yes");  
            else  
            puts("No");  
        }  
    }  
    return 0;  
} 