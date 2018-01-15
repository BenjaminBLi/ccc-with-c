#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i <= (int) (en); i++)
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

const int MAXN = 100010;
int rnk[MAXN], n, m;

inline void init(){
  fori(i, 1, n) rnk[i] = -1;
}

int find(int x){
  return rnk[x] < 0 ? x : rnk[x] = find(rnk[x]);
}

bool us(int u, int v){
  if((u = find(u)) != (v = find(v))){
    if(rnk[u] > rnk[v]) swap(u, v);
    rnk[u] += rnk[v];
    return rnk[v] = u;
  }
  return false;
}

int main(){
  scanf("%d%d", &n, &m);
  vi ans;
  init();
  fori(i, 1, m){
    int u, v;
    scanf("%d%d", &u, &v);
    if(us(u, v)) ans.pb(i);
  }
  if(ans.size() == n-1) for(int id : ans) printf("%d\n", id);
  else printf("Disconnected Graph\n");
  return 0;
}

