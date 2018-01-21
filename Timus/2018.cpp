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

const ll mod = 1e9+7;
const int MAXN = 50010;
int n, a, b;
ll memo[MAXN][2];

ll solve(int idx, int flag){
  if(idx == n) return 1;
  ll &curr = memo[idx][flag];
  if(curr != -1) return curr;

  int en = n;
  if(flag) en = min(en, idx + b);
  else en = min(en, idx + a);

  curr = 0;
  fori(i, idx+1, en+1)
    curr = (curr + solve(i, 1-flag))%mod;
  
  return curr;
}

int main(){
  memset(memo, -1, sizeof memo);
  scanf("%d%d%d", &n, &a, &b);
  printf("%lld\n", (solve(0, 0) + solve(0, 1))%mod);
  return 0;
}

