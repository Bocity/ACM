#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define DE cout << "fuckstay" << endl
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
int ans  = 0;
int n, m,nn;
struct NNode {
  int ad;
};
queue<char> anss;
map<char,int> vis;
map<char,int> vis2;
int c[10000];
int G[100][100]{0};
int topo[10000], t;
bool dfs(int u){
    c[u] = -1;
    for(int v = 0; v < n; ++v){
        if (G[u][v]){
            if (c[v] < 0) return false;
            else if (!c[v] && !dfs(v)) return false;
        }
    }
    c[u] = 1;
    topo[--t] = u;
    return true;
}
bool toposort(){
    t = n;
    memset(c,0,sizeof (c));
    for(int u = 0; u < n; u ++) if (!c[u])
        if (!dfs(u)) return false;
    return true;
}

class TrieTree {
#define N 20005
#define M 26
private:
  struct TrieNode {
    int cnt;
    vector<char> rank;
    NNode node[M];
    TrieNode() {
      cnt = 0;
      memset(node, 0, sizeof node);
    }

  } ch[N];
  int sz;
public:
  void init() { sz = 0; }
  void insert(char *s) {
    int u = 0, len = strlen(s);
    for (int i = 0; i < len; ++i) {
      int c = s[i] - 'a';
      ch[u].rank.push_back(s[i]);
      if (ch[u].node[c].ad == 0) {
        ch[u].node[c].ad = ++sz;
        //cout << u << " - " << c <<  " " <<ch[u].node[c].ad <<endl;
       // cout << sz;
        u = sz;
      } else {
        // if (i+1 < len && ch[ch[u].node[c].ad].node[s[i+1]-'a'].ad == 0){
        //     ch[u].node[c].rank.push_back(s[i+1]);
        // }
        u = ch[u].node[c].ad;
      }
      ch[u].cnt++;
    }
  }
  void bfs(){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        //cout << u << endl;
            REP(j,0,ch[u].rank.size()){
                REP(k,j+1,ch[u].rank.size()){
                    if (ch[u].rank[j] !=ch[u].rank[k]){
                    G[ch[u].rank[j]-'a'][ch[u].rank[k]-'a'] = 1;
                    //cout << ch[u].rank[j] << " > " << ch[u].rank[k] << endl;
                    }
                }
            }
            REP(i,0,26){
                if (ch[u].node[i].ad != 0)
                q.push(ch[u].node[i].ad);
            }
        }
    }
} trie;

string s[1000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> nn;
  n = 26;
  trie.init();
  REP(i,0,nn){
      cin >> s[i];
      trie.insert((char *)s[i].c_str());
  }
  REP(i,0,nn){
      REP(j,0,i){
          if (s[i].size() < s[j].size()){
            if (s[j].find(s[i]) == 0){
                cout <<  "Impossible" << endl;
                return 0;
            }
          }
      }
  }
   trie.bfs();
   if (!toposort()){
       cout << "Impossible" << endl;
   }else{

       REP(i,0,26){
           cout << (char) (topo[i] + 'a');
       }
   }
  return 0;
}