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

const int MAXN = 100010;
int n, m, rem[MAXN], rnk[MAXN], cnt;
bool marked[MAXN];
ii es[MAXN];

void init(){fori(i, 0, MAXN) rnk[i] = -1;}
int fs(int u){return rnk[u] < 0 ? u : rnk[u] = fs(rnk[u]);}
bool us(int u, int v){
  if((u = fs(u)) != (v = fs(v))){
    cnt--;
    if(rnk[u] > rnk[v]) swap(u, v);
    rnk[u] += rnk[v];
    rnk[v] = u;
    return true;
  }
  return false;
}

int main(){
  init();
  scanf("%d%d", &n, &m);
  cnt = n;
  fori(i, 1, m+1){
    scanf("%d%d", &es[i].f, &es[i].s);
  }

  int q;
  scanf("%d", &q);
  fori(i, 0, q) {
    scanf("%d", rem+i);
    marked[rem[i]] = true;
  }

  fori(i, 1, m+1){
    if(marked[i]) continue;
    us(es[i].f, es[i].s);
  }

  vi ans;
  rfori(i, q-1, 0){
    //check each , 
    ans.pb(cnt);
    us(es[rem[i]].f, es[rem[i]].s);
  }

  rfori(i, q-1, 0) printf("%d ", ans[i]);cout<<endl;


  
  return 0;
}

