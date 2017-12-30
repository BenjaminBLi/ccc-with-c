#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define forie(i, st, en) for(int i = st; i <= (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first #define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

struct edge{
  int u, v, w;
  bool operator < (const edge &o) const{
    return w > o.w;
  }
};

//disjoint set
int p[110], rnk[110];

int fs(int i){return (p[i] == i ? i : (p[i] = fs(p[i])));}
bool ss(int u, int v){return fs(u) == fs(v);}
void us(int u, int v){
  if(ss(u, v)) return;

  int x = fs(u), y = fs(v);
  if(rnk[x] > rnk[y]) p[y] = x;
  else{
    p[x] = y;
    if(rnk[x] == rnk[y]) rnk[y]++;
  }
}

int n, pens = 0, cost[1010][1010];
vi fence[1010][1010], adj[1010];
bool vis[110];

void dfs(int u){
  vis[u] = true;
  for(int v : adj[u]){
    if(vis[v]) continue;
    dfs(v);
  }
}

int main(){
  scanf("%d", &n);
  priority_queue<edge> pq;

  //construct graph
  fori(i, 0, n){
    vi curr;
    int cnt;

    scanf("%d", &cnt);
    fori(j, 0, cnt){
      int pt;
      scanf("%d", &pt);

      pens = max(pens, pt);
      curr.pb(pt);
    }

    for(int j = 0, w; j < cnt; j++){
      scanf("%d", &w);

      int u = curr[j], v = curr[(j+1)%cnt];
      //printf("{<%d, %d>: %d}, ", u, v, w);
      fence[u][v].pb(i);
      fence[v][u].pb(i);
      cost[u][v] = cost[v][u] = w;
    }
  }

  //calculate which edges need to be used in the priority queue, and which edges will be used to check the connectivity of the graph.
  //fence is used to keep track of how many pens share the edge
  forie(i, 0, pens){
    forie(j, i+1, pens){
      if(fence[i][j].size() == 1){
        pq.push({fence[i][j][0], n, cost[i][j]});
      }else if(fence[i][j].size() == 2){
        adj[fence[i][j][0]].pb(fence[i][j][1]);
        adj[fence[i][j][1]].pb(fence[i][j][0]);
        pq.push({fence[i][j][0], fence[i][j][1], cost[i][j]});
      }
    }
  }

  //check if all pens are connected
  dfs(0);
  bool connected = true;
  fori(i, 0, n) connected &= vis[i];

  //do kruskal's to get the mst
  forie(i, 0, n) p[i] = i;

  int cnt = 0, extra = 0, ans = 0;
  while(pq.size() && cnt <= n){
    edge e = pq.top(); pq.pop();
    if(!ss(e.u, e.v)){
      ans += e.w;
      cnt++;
      us(e.u, e.v);
      if(e.u == n || e.v == n) extra = e.w;
    }
  }

  if(connected) printf("%d\n", ans-extra);
  else printf("%d\n", ans);

  return 0;
}
