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
ll a[10010];

int main(){
  scanf("%d", &n);
  fori(i, 1, n+1){
    scanf("%lld", a+i);
    a[i] += a[i-1];
  }

  int q;
  scanf("%d", &q);
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%lld\n", a[r]-a[l-1]);
  }
  return 0;
}

