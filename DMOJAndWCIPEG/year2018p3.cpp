#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i <= (int) (en); i++)
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

const int MAXN = 100010;
int m, n, k;
ll a[MAXN], diff[MAXN];

bool check(ll sz){
  ll cnt = 0;
  fori(i, 1, n){
    diff[i] += diff[i-1];
    if(a[i] + diff[i] < sz){
      int rem = sz-(a[i] + diff[i]);
      cnt += rem;
      diff[i] += rem;
      diff[min(n+1, i+m)] -= rem;
    }
    diff[i-1] = 0;
  }
  diff[n] = 0;
  return cnt <= k;
}

int main(){
  scanf("%d%d%d", &n, &m, &k);
  fori(i, 1, n)
    scanf("%lld", a+i);

  ll lo = 0, hi = 1LL<<32, mid;
  while(lo < hi){
    mid = lo + (hi - lo)/2;
    if(check(mid)){
      lo = mid+1;
    }else{
      hi = mid;
    }
  }

  cout << lo-1 << endl;
  return 0;
}

