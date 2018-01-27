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

const int MAXN = 10010;
int n, k, m;
vi adj[MAXN];
bool vis[MAXN];

void dfs(int u){
  vis[u] = true;
  for(int v : adj[u]) if(!vis[v]) dfs(v);
}

int main(){
  scanf("%d%d%d", &n, &k, &m);
  fori(i, 0, k){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }

  int cnt = 0;
  fori(i, 1, n+1){
    if(!vis[i]){
      dfs(i);
      cnt++;
    }
  }

  cout << cnt-1 << endl;
  return 0;
}

