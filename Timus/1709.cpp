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

int n, d, a, vis[110], col, ans[110][110], adj[110][110], rnk[110];
ll cost = 0;

void init(){fori(i, 0, 110) rnk[i] = -1;}
int fs(int u){return rnk[u] < 0 ? u : rnk[u] = fs(rnk[u]);}
bool us(int u, int v){
  if((u = fs(u)) != (v = fs(v))){
    if(rnk[u] > rnk[v]) swap(u, v);
    rnk[u] += rnk[v];
    rnk[v] = u;
    return true;
  }
  return false;
}

void dfs(int u){
  vis[u] = col;
  fori(v, 1, n+1){
    if(vis[v] != 0 || !adj[u][v]) continue;
    cost -= 2;
    ans[u][v] = ans[v][u] = true;
    dfs(v);
  }
}

int main(){
  init();
  scanf("%d%d%d", &n, &d, &a);
  fori(i, 1, n+1) fori(j, 1, n+1){
    char ch;
    scanf(" %c", &ch);
    if(ch == '1'){
      cost++;
      adj[i][j] = true;
      us(i, j);
    }
  }

  //dfs through each component
  fori(i, 1, n+1){
    if(!vis[i]){
      col++;
      dfs(i);
    }
  }

  fori(i, 1, n+1){
    fori(j, 1, n+1){
      if(us(i, j)){
        ans[i][j] = ans[j][i] = 2;
      }
    }
  }

  cost = 1LL*cost*d/2 + 1LL*a*(col-1);

  cout << cost << endl;
  fori(i, 1, n+1){
    fori(j, 1, n+1){
      if(ans[i][j] == 0 && adj[i][j] == 1) putchar('d');
      else if(ans[i][j] == 2) putchar('a');
      else putchar('0');
    }
    putchar('\n');
  }


  return 0;
}

