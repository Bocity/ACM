#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400005 ;
const int N = 26 ;
char str1[MAXN];
char str2[MAXN];

struct Palindromic_Tree {
    int slen,slen1;
    int next[MAXN][N] ;//next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成
    int fail[MAXN] ;//fail指针，失配后跳转到fail指针指向的节点
    long long cnt[MAXN] ;
    long long cnt1[MAXN] ;
    int num[MAXN] ;
    int len[MAXN] ;//len[i]表示节点i表示的回文串的长度
    int S[MAXN] ;//存放添加的字符
    int last ;//指向上一个字符所在的节点，方便下一次add
    int n ;//字符数组指针
    int p ;//节点指针
    int newnode ( int l ) {//新建节点
        for ( int i = 0 ; i < N ; ++ i ) next[p][i] = 0 ;
        cnt[p] = 0 ;
        num[p] = 0 ;
        len[p] = l ;
        return p ++ ;
    }
    void init () {//初始化
        for(int i=0;i<=slen+slen1+4;i++)
        {
            cnt1[i]=cnt[i]=0;
        }

        p = 0 ;
        newnode (  0 ) ;
        newnode ( -1 ) ;
        last = 0 ;
        n = 0 ;
        S[n] = -1 ;//开头放一个字符集中没有的字符，减少特判
        fail[0] = 1 ;
    }
    void init1()
    {
        last=0;
        n=0;
        S[n]=-1;
        fail[n]=1;
    }
    int get_fail ( int x ) {//和KMP一样，失配后找一个尽量最长的
        while(S[n-len[x]- 1]!= S[n])
            x = fail[x] ;
        return x ;
    }

    void add ( int c ) {
        c -= 'a' ;
        S[++ n] = c ;
        int cur = get_fail ( last ) ;//通过上一个回文串找这个回文串的匹配位置
        if ( !next[cur][c] ) {//如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int now = newnode ( len[cur] + 2 ) ;//新建节点
            fail[now] = next[get_fail ( fail[cur] )][c] ;//和AC自动机一样建立fail指针，以便失配后跳转
            next[cur][c] = now ;
            num[now] = num[fail[now]] + 1 ;
        }
        last = next[cur][c] ;
        cnt[last] ++ ;
    }

    void add1(int c)
    {
        c -= 'a' ;
        S[++ n] = c ;
        int cur = get_fail ( last ) ;//通过上一个回文串找这个回文串的匹配位置
        if ( !next[cur][c] ) {//如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int now = newnode ( len[cur] + 2 ) ;//新建节点
            fail[now] = next[get_fail ( fail[cur] )][c] ;//和AC自动机一样建立fail指针，以便失配后跳转
            next[cur][c] = now ;
            num[now] = num[fail[now]] + 1 ;
        }
        last = next[cur][c] ;
        cnt1[last] ++ ;

    }

    void count () {
        for ( int i = p - 1 ; i >= 0 ; -- i )
            cnt[fail[i]] += cnt[i] ;
        //父亲累加儿子的cnt，因为如果fail[v]=u，则u一定是v的子回文串！
    }
    void count1()
    {
        for ( int i = p - 1 ; i >= 0 ; -- i )
            cnt1[fail[i]] += cnt1[i] ;
    }
} tree;

int main()
{
    int n;
    scanf("%d",&n);
    int k=1;
    while(n--)
    {
        scanf("%s%s",str1,str2);
        tree.init();
        tree.slen=strlen(str1);
        tree.slen1=strlen(str2);
        for(int i=0;i<tree.slen;i++)
            tree.add(str1[i]);
        tree.count();
        tree.init1();
        for(int i=0;i<tree.slen1;i++)
            tree.add1(str2[i]);
        tree.count1();
        long long ans=0;
        for(int i=2;i<=tree.p-1;i++)
        {
            ans+=tree.cnt[i]*tree.cnt1[i];
        }
        printf("Case #%d: %lld\n",k++,ans);
    }
}