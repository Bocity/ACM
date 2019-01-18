#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <stdio.h>
#include <time.h>
using namespace std;
#define LL long long
#define pi acos(-1.0)
#pragma comment(linker, "/STACK:1024000000")
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eqs=1e-9;
const int MAXN=100000+10;
int a[MAXN];
LL ha[MAXN], ans[MAXN], res;
struct node {
        int l, r, id, pos;
} fei[MAXN];
bool cmp(node x, node y)
{
        return x.pos<y.pos||x.pos==y.pos&&x.r<y.r;
}
void reduce(int tmp)
{
        if(ha[tmp-1]&&ha[tmp+1]) res++;
        else if(!ha[tmp-1]&&!ha[tmp+1]) res--;
        ha[tmp]=0;
}
void add(int tmp)
{
        if(ha[tmp-1]&&ha[tmp+1]) res--;
        else if(!ha[tmp-1]&&!ha[tmp+1]) res++;
        ha[tmp]=1;
}
int main()
{
        int t, n, m, i, j, k, tmp, l, r;
        scanf("%d",&t);
        while(t--) {
                scanf("%d%d",&n,&m);
                for(i=1; i<=n; i++) {
                        scanf("%d",&a[i]);
                }
                k=sqrt(n*1.0);
                for(i=0; i<m; i++) {
                        scanf("%d%d",&fei[i].l,&fei[i].r);
                        fei[i].id=i;
                        fei[i].pos=fei[i].l/k;
                }
                sort(fei,fei+m,cmp);
                memset(ha,0,sizeof(ha));
                l=1;
                r=0;
                res=0;
                for(i=0; i<m; i++) {
                        while(r>fei[i].r) {
                                tmp=a[r];
                                reduce(tmp);
                                r--;
                        }
                        while(r<fei[i].r) {
                                r++;
                                tmp=a[r];
                                add(tmp);
                        }
                        while(l<fei[i].l) {
                                tmp=a[l];
                                reduce(tmp);
                                l++;
                        }
                        while(l>fei[i].l) {
                                l--;
                                tmp=a[l];
                                add(tmp);
                        }
                        ans[fei[i].id]=res;
                }
                for(i=0; i<m; i++) {
                        printf("%I64d\n",ans[i]);
                }
        }
        return 0;
}