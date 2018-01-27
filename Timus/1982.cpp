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

struct edge{
  int u, v, w;
  edge(int a, int b, int c){u = a, v = b, w = c;}
  bool operator < (const edge &o) const{
    if(w != o.w) return w > o.w;
    if(u != o.u) return u < o.u;
    return v < o.v;
  }
};

int k, n, adj[110][110], rnk[110];

void init(){fori(i, 0, 110) rnk[i] = -1;};
int find(int x){return rnk[x] < 0 ? x : rnk[x] = find(rnk[x]);}
bool us(int u, int v){
  if((u = find(u)) != (v = find(v))){
    if(rnk[u] > rnk[v]) swap(u, v);
    rnk[u] += rnk[v];
    rnk[v] = u;
    return true;
  }
  return false;
}

int main(){
  scanf("%d%d", &n, &k);
  init();
  for(int i = 0, u; i < k; i++){
    scanf("%d", &u);
    us(0, u);
  }

  priority_queue<edge, vector<edge>> pq;

  fori(i, 0, n){
    fori(j, 0, n){
      int w;
      scanf("%d", &w);
      pq.push(edge(i+1, j+1, w));
    }
  }

  ll ans = 0;
  while(pq.size()) {
    edge c = pq.top(); pq.pop();
    if(us(c.u, c.v)){
      ans += c.w;
    }
  }

  cout << ans << endl;
  return 0;
}

