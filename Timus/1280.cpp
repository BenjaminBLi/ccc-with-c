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

const int MAXN = 1010;
vi adj[MAXN];
int n,m, in[MAXN];

int main(){
  scanf("%d%d", &n, &m);
  fori(i, 0, m){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    in[v]++;
  }

  queue<int> q;

  fori(i, 0, n){
    int u;
    scanf("%d", &u);
    q.push(u);
  }

  bool ok = true;
  while(q.size() && ok){
    int u = q.front(); q.pop();
    ok &= in[u] == 0;
    for(int v : adj[u])
      in[v]--;
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}

