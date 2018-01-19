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

int k, a[110];

int main(){
  scanf("%d", &k);
  fori(i, 0, k) scanf("%d", a+i);
  sort(a, a+k);
  int en = (k + 1)/2;
  int ans = 0;
  fori(i, 0, en) ans += a[i]+1>>1;
  cout << ans << endl;
  return 0;
}

