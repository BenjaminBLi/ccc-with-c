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

const int MAXN = 110;
int n, cnt = 0, vis[MAXN];
vi adj[MAXN];
bool ok = true;

void dfs(int u, int col){
  vis[u] = col;
  if(col == 1) cnt++;
  for(int v : adj[u]) {
    if(vis[v] == -1) dfs(v, col^1);
  }
}

int main(){
  memset(vis, -1, sizeof vis);
  scanf("%d", &n);
  for(int u = 1, v;  u <= n; u++)
    for(scanf("%d", &v); v; scanf("%d", &v)) adj[u].pb(v);

  fori(i, 1, n+1){
    if(vis[i] == -1) dfs(i, 1);
  }

  printf("%d\n", cnt);
  fori(i, 1, n+1) if(vis[i] == 1) printf("%d ", i);
  printf("\n");


  return 0;
}

