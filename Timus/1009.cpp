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

int n, k;
ll memo[20][2];

ll solve(int len, bool flag){
  ll &curr = memo[len][flag];
  if(curr != -1) return curr;
  if(len == 0)
    return 1;

  curr = 0;
  fori(i, 0, k){
    if(flag && i == 0) continue;
    curr += solve(len-1, i == 0);
  }
  return curr;
}

int main(){
  memset(memo, -1, sizeof(memo));
  scanf("%d%d", &n, &k);
  cout << solve(n, true) << endl;
  return 0;
}

