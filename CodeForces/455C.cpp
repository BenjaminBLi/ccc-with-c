#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

const int MAXN = 300500;
int n, m, q, rnk[MAXN], st, diam[MAXN], sz, bst;
bool vis[MAXN];
vi adj[MAXN];

//disjoint set shit
inline void init(){fori(i, 0, n+1) rnk[i] = -1;}
int find(int x){return rnk[x] < 0 ? x : rnk[x] = find(rnk[x]);}
bool us(int u, int v){
  if((u = find(u)) != (v = find(v))){
    if(rnk[u] > rnk[v]) swap(u, v);
    rnk[u] += rnk[v];
    return rnk[v] = u;
  }
  return false;
}

//diameter finding void dfs(int u, int p){
void dfs(int u, int p){
  vis[u] = true;
  sz++;
  for(int v : adj[u]){
    if(v == p) continue;
    dfs(v, u);
  }
  if(sz > bst){
    st = u;
    bst = sz;
  }
  sz--;
}

int main(){
  scanf("%d%d%d", &n, &m, &q);
  init();
  for(int i = 0, u, v; i < m; i++){
    scanf("%d%d", &u, &v);
    adj[u].pb(v); adj[v].pb(u);
    us(u, v);
  }

  fori(i, 0, n+1){
    int p = find(i);
    if(!vis[p]){
      vis[p] = true;
      bst = sz = 0, st = i;
      dfs(st, st);
      dfs(st, st);
      diam[find(st)] = bst-1;
    }
  }

  int id, x, y;
  while(q--){
    scanf("%d%d", &id, &x);
    if(id == 1){
      printf("%d\n", diam[find(x)]);
    }else{
      scanf("%d", &y);
      int cmax = max(diam[find(x)], diam[find(y)]);
      int ndiam = ((diam[find(x)]+1)>>1) + ((diam[find(y)]+1)>>1) + 1;
      if(!us(x, y)) continue;
      ndiam = max(ndiam, cmax);
      diam[find(y)] = ndiam;
    }
  }

  return 0;
}

