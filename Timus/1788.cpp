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

int n, m, a[110], b[110];

bool cmp(int a, int b){return a > b;}

int calc(int piv){
  //take all the girls before piviot
  int ret = 0;
  fori(i, piv, n) ret += a[i];
  fori(i, piv, m) ret += piv*b[i];
  return ret;
}

int main(){
  scanf("%d%d", &n, &m);
  fori(i, 0, n) scanf("%d", a+i);
  fori(i, 0, m) scanf("%d", b+i);

  sort(a, a+n, cmp);
  sort(b, b+m, cmp);
  int en = min(n, m);

  int ans = 1<<30;
  fori(piv, 0, en+1)
    ans = min(ans, calc(piv));
  
  cout << ans << endl;

  return 0;
}

