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
const double diag = 141.421356237;
int n, m, k;
double memo[MAXN][MAXN];
bool ok[MAXN][MAXN];

bool valid(int r, int c){
  return 0 <= r && r <= n && 0 <= c && c <= m;
}

int main(){
  scanf("%d%d%d", &n, &m, &k);

  for(int i = 0, r, c; i < k; i++){
    scanf("%d%d", &r, &c);
    ok[r][c] = true;
  }

  fori(i, 0, n+1) fori(j, 0, m+1) memo[i][j] = 10000000;

  memo[0][0] = 0;

  //do dp from (0, 0) to (n, m)
  fori(r, 0, n+1) fori(c, 0, m+1){
    if(ok[r+1][c+1] && memo[r+1][c+1] > memo[r][c] + diag) memo[r+1][c+1] = memo[r][c] + diag;

    for(int dx = 0; dx <= 1; dx++) for(int dy = 0; dy <= 1; dy++){
      if(abs(dx + dy) == 1 && memo[r + dx][c + dy] >= memo[r][c] + 100) 
        memo[r + dx][c + dy] = memo[r][c] + 100;
    }
  }

  cout << round(memo[n][m]) << endl;
  

  return 0;
}

