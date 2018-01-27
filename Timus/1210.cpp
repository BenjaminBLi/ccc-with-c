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

int n, memo[31][31], sz[31];
vii adj[31][31];

int main(){
  scanf("%d", &n);
  fori(level, 1, n+1){
    int k;
    scanf("%d", &k);
    sz[level] = k;
    int u, w;
    fori(v, 1, k+1){
      scanf("%d", &u);
      while(u){
        scanf("%d", &w);
        adj[level-1][u].pb(ii(v, w));
        scanf("%d", &u);
      }
    }
    scanf("\n*");
  }

  sz[0] = 1;
  memset(memo, 0x3f, sizeof memo);
  memo[0][1] = 0;
  fori(level, 0, n){
    //kms do dp and shit
    fori(planet, 1, sz[level]+1){
      //for each planet just like check best[level+1][v]
      int c = memo[level][planet];
      for(ii e : adj[level][planet]){
        if(memo[level+1][e.f] > c + e.s)
          memo[level+1][e.f] = c + e.s;
      }
    }
  }

  int bst = 0x3f3f3f3f;
  fori(i, 1, sz[n]+1) bst = min(bst, memo[n][i]);
  cout << bst << endl;


  return 0;
}

