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
int n, in[MAXN];
vi adj[MAXN];

int main(){
  scanf("%d", &n);
  fori(i, 1, n+1){
    int u;
    scanf("%d", &u);
    while(u){
      adj[i].pb(u);
      in[u]++;
      scanf("%d", &u);
    }
  }

  queue<int> q;

  fori(i, 1, n+1) if(in[i] == 0) q.push(i);

  while(q.size()){
    int u = q.front(); q.pop();
    printf("%d ", u);
    for(int v : adj[u]){
      if(--in[v] == 0) q.push(v);
    }
  }
  cout << endl;
  return 0;
}

