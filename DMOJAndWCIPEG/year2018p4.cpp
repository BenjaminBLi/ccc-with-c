#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

int digit[20];
ll l, r, memo[163][20];    

ll f(int sum, int pos, bool prevMx){
  //cout << sum << ", " << pos << endl;
  if(sum < 0) return 0;
  if(pos == 0) return sum == 0 ? 1 : 0;

  if(!prevMx && memo[sum][pos] != -1) return memo[sum][pos];
  
  ll curr = 0;
  int bound = prevMx ? digit[pos] : 9;

  fori(i, 0, bound+1)
    curr += f(sum-i, pos-1, prevMx&& (i == digit[pos]));

  if(!prevMx) return memo[sum][pos] = curr;
  return curr;
}

ll solve(ll val, int s){
  fori(i, 0, 20) digit[i] = 0;

  int cnt = 0;
  while(val) digit[++cnt] = val%10, val /= 10;

  return f(s, cnt, true);
}


int main(){
  memset(memo, -1, sizeof(memo));
  scanf("%lld%lld", &l, &r);

  int ans = 0;
  fori(i, 1, 163) if(solve(r, i) > solve(l-1, i)) ans++;

  cout << ans << endl;

  return 0;
}

