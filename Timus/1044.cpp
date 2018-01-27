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

int k, cnt[50];

void solve(int idx, int sum){
  if(idx == k/2) {
    cnt[sum]++;
    return;
  }

  fori(i, 0, 10) solve(idx+1, sum+i);
}

int main(){
  scanf("%d", &k);
  solve(0, 0);
  int ans = 0;
  fori(i, 0, 50) ans += cnt[i]*cnt[i];
  cout << ans << endl;
  return 0;
}

