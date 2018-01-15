#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
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

const int MAXN = 200010;

int n, x, ft[MAXN<<1];
ii pts[MAXN], coords[MAXN];
double ms[MAXN<<1];
pair<lf, lf> both[MAXN];

void upd(int i){for(; i < 2*MAXN; i += (i & (-i))) ft[i]++;}
int qry(int idx){
  int ret = 0;
  for(; idx; idx -= idx & (-idx)) {
    ret += ft[idx];
  }
  return ret;
}

int main(){
  scanf("%d%d", &n, &x);
  int sz = 0;
  fori(i, 0, n) {
    scanf("%d%d", &pts[i].f, &pts[i].s);
    double ang1 = atan((lf)pts[i].s/(lf)pts[i].f);
    double ang2 = atan((lf)pts[i].s/(((lf)x-(lf)pts[i].f)));
    ms[sz++] = ang1, ms[sz++] = ang2;
    both[i] = {ang1, ang2};
  }

  sort(ms, ms+sz);

  //get ordering of points for processing

  fori(i, 0, n){
    coords[i].f = sz - (lower_bound(ms, ms+sz, both[i].f)-ms) + 2;
    coords[i].s = sz - (lower_bound(ms, ms+sz, both[i].s)-ms) + 2;
  }

  sort(coords, coords+n);

  ll ans = 0;
  fori(i, 0, n){
    ll curr = qry(coords[i].s);
    ans += curr*curr;
    upd(coords[i].s);
  }

  cout << ans << endl;
  return 0;
}

