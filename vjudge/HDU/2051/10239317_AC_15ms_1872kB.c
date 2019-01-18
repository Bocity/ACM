#include <stdio.h>  
  
int a[1005][10];  
  
int main(){  
  
    int i,j,n;  
      
    for(i = 1; i <= 1000; i ++)  
    {  
        j = 10;  
        int temp = i;  
          
        while(temp){  
            a[i][j --] = temp % 2;  
            temp /= 2;  
        }  
    }  
      
    while(scanf("%d",&n) != EOF){  
        int flag = 0;  
        for(j = 1; j <= 10; j ++){  
            if(a[n][j])  
                flag = 1;  
              
            if(flag)  
                printf("%d",a[n][j]);  
        }  
        putchar('\n');  
    }  
    return 0;  
}  