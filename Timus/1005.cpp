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

int memo[1<<20], n, a[20], tot = 0;

int main(){
  scanf("%d", &n);

  fori(i, 0, n){
    scanf("%d", a+i);
    tot += a[i];
  }

  int bst = 1<<30;

  fori(mask, 0, 1<<n){
    int cs = 0;
    fori(i, 0, n) if(mask & (1<<i)) cs += a[i];
    int o = tot - cs;
    if(bst > abs(o-cs)) bst = abs(o-cs);
  }

  cout << bst << endl;

  return 0;
}

