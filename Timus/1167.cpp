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

int N, K, cnt[510], memo[510][510];

int solve(int n, int k){
  if(k == 1) return cnt[n] * (n - cnt[n]);

  int &ret = memo[n][k];
  if(ret != -1) return ret;

  for(int i = 1; n-i >= k && i <= n; i++){
    int curr = (cnt[n]-cnt[n-i]) * (i - (cnt[n] - cnt[n-i])) + solve(n-i, k-1);
    if(ret == -1 || ret > curr) ret = curr;
  }

  return ret;
}

int main(){
  memset(memo, -1, sizeof memo);
  scanf("%d%d", &N, &K);

  cnt[0] = 0;
  fori(i, 1, N+1){
    int x;
    scanf("%d", &x);
    cnt[i] += cnt[i-1] + x;
  }

  cout << solve(N, K) << endl;
  return 0;
}
