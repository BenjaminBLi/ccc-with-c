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

ll x, y;

int main(){
  scanf("%lld%lld", &x, &y);
  if((x + y) % 2 == 0 || x < 0 || y < 0) printf("%lld %lld\n", x, y);
  else printf("%lld %lld\n", y, x);
  return 0;
}

