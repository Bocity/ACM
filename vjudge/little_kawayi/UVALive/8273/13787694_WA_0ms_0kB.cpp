#include<iostream>  
using namespace std;  
  
typedef class  
{  
    public:  
        int next[27];  //直接后继  
        int pn;   //next[]指针（后继个数）  
}point;  
  
int main()  
{  
    int i,j,k;
    int n;  
    int t;
    cin >> t;
    while(t--)  
    {  
        cin >>n;
        // if(!n)  
        //     break;  
  
        // getchar();  //n的换行符  
  
        point* node=new point[n+1];  //结点  
  
        /*Structure the Map*/  
        int p;
        cin >> p;
        for(int i = 1; i <= n; ++i){
            node[i].pn=0; 
        }
        for(int i = 0; i < p; ++i){
            int x,y;
            cin >> x >> y;
            x++;
            y++;
            node[x].next[++node[x].pn] = y;
            node[y].next[++node[y].pn] = x;
        }
        // for(i=1;i<=n;i++)  
        // {  
        //     getchar();  //结点序号  
        //     getchar();  //冒号  
  
        //     if(node[i].pn<0)   //初始化指针  
        //         node[i].pn=0;  
  
        //     char ch;  
        //     while((ch=getchar())!='\n')  
        //     {  
        //         j=ch%('A'-1);   //把结点字母转换为相应的数字，如A->1  C->3  
        //         node[i].next[ ++node[i].pn ]=j;  
        //     }  
        // }  
  
        int color[27]={0};  //color[i]为第i个结点当前染的颜色，0为无色（无染色）  
        color[1]=1;  //结点A初始化染第1种色  
        int maxcolor=1;  //当前已使用不同颜色的种数  
  
        for(i=1;i<=n;i++)  //枚举每个顶点  
        {  
            color[i]=n+1;  //先假设结点i染最大的颜色  
            bool vist[27]={false};  //标记第i种颜色是否在当前结点的相邻结点染过  
            for(j=1;j<=node[i].pn;j++) //枚举顶点i的所有后继  
            {  
                int k=node[i].next[j];  
                if(color[k])  //顶点i的第j个直接后继已染色  
                    vist[ color[k] ]=true;  //标记该种颜色  
            }  
            for(j=1;i<=n;j++)  //从最小的颜色开始，枚举每种颜色，最终确定结点i的染色  
                if(!vist[j] && color[i]>j)  
                {  
                    color[i]=j;  
                    break;  
                }  
  
            if(maxcolor<color[i])  
                maxcolor=color[i];  
        }  
  
        if(maxcolor<=3)  
            cout<<"Y"<<endl;  
        else  
            cout<<"N"<<endl;  
  
        delete node;  
    }  
    return 0;  
}  