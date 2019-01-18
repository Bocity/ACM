#include<cstdio>
 #include<cstring>
 #include<string>
 #include<algorithm>
 #include<map>
 using namespace std;
 
 map<string,int>ma;
 char str1[131],str2[131];
 double a[33][33],d[33][33];
 int n;
 
 void init_d()
 {
     for (int i=0;i<n;i++)
     {
         for (int j=0;j<n;j++)
         {
             if (i==j)
             {
                 d[i][j]=1;
             }
             else
             {
                 d[i][j]=0;
             }
         }
     }
 }
 
 int main(void)
 {
     int cnt=0;
     while (scanf("%d",&n),n)
     {
         getchar();
         init_d();
         for (int i=0;i<n;i++)
         {
             gets(str1);
             ma[str1]=i;
         }
         int m;
         scanf("%d",&m);
         getchar();
         double data;
         for (int i=0;i<m;i++)
         {
             scanf("%s %lf %s",str1,&data,str2);
             getchar();
             d[ma[str1]][ma[str2]]=data;
         }
         for (int i=0;i<n;i++)
         {
             for (int j=0;j<n;j++)
             {
                 if (d[j][i]>0)
                 {
                     for (int k=0;k<n;k++)
                     {
                         d[j][k]=max(d[j][k],d[j][i]*d[i][k]);
                     }
                 }
             }
         }
         int i;
         for (i=0;i<n;i++)
         {
             if (d[i][i]>1)
             {
                 printf("Case %d: Yes\n",++cnt);
                 break;
             }
         }
         if (n==i)
         {
             printf("Case %d: No\n",++cnt);
         }
     }
     return 0;
 }
 