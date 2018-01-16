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

int n;
ii pts[150010];

bool cmp(ii a, ii b){
  return a.s > b.s;
}

int main(){
  scanf("%d", &n);
  fori(i, 0, n) scanf("%d%d", &pts[i].f, &pts[i].s);
  stable_sort(pts, pts + n, cmp);
  fori(i, 0, n) printf("%d %d\n", pts[i].f, pts[i].s);
  return 0;
}

