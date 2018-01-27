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

int n, memo[60010], coins[60010];

int solve(int n){
}

int main(){
  scanf("%d", &n);
  int sz = 0;
  for(int i = 1; i*i <= n; i++) coins[sz++] = i*i;
  memset(memo, 0x3f, sizeof memo);
  memo[0] = 0;
  fori(i, 1, n+1){
    fori(j, 0, sz){
      if(coins[j] > i) continue;
      memo[i] = min(memo[i], memo[i-coins[j]] + 1);
    }
  }

  cout << memo[n] << endl;
  return 0;
}

