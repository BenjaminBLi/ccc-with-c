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

const int MAXN = 210, mod = 1e9+7, root = 0;
int n, W, m;
bool isroot[MAXN];
ll memo[MAXN][MAXN][2];
vii adj[MAXN];

void solve(int u){
  memo[u][0][0] = memo[u][1][1] = 1;

  for(ii e : adj[u]){
    int v = e.f;
    int flag = e.s;
    solve(e.f);
    rfori(w, W, 0) {
      ll wolf = 0, civ = 0;
      fori(k, 0, w+1){
        //if current is civillian, count all possibilities
        civ += (memo[v][k][0] + memo[v][k][1]) * memo[u][w-k][0];
        civ %= mod;

        wolf += memo[v][k][flag] * memo[u][w-k][1];
        wolf %= mod;
      }
      memo[u][w][0] = civ;
      memo[u][w][1] = wolf;
    }
  }
}

int main(){
  scanf("%d%d%d", &n, &W, &m);

  fori(i, 0, m){
    int u, v;
    char ch; 
    scanf(" %c%d%d", &ch, &u, &v); 
    if(ch == 'A') ch = 0;
    else ch = 1;
    isroot[v] = true;
    adj[u].pb(ii(v, ch));
  }

  fori(i, 1, n+1) if(!isroot[i]) adj[root].pb(ii(i, 0));

  solve(root);
  
  cout << memo[root][W][0] << endl;

  return 0;
}

