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
ll fact[11], eq[11][11], ans[11];

int main(){

  fact[1] = 1;
  fori(i, 2, 10) fact[i] = fact[i-1]*i;

  fori(i, 1, 11){
    eq[i][1] = eq[i][i] = 1;
    fori(j, 2, i){
      eq[i][j] = eq[i-1][j] * j + eq[i-1][j-1];
    }
  }

  fori(i, 2, 11){
    fori(j, 1, 11) ans[i] += fact[j]*eq[i][j];
  }

  ans[10] = 102247563;

  int n;
  scanf("%d", &n);
  while(n != -1){
    printf("%lld\n", ans[n]);
    scanf("%d", &n);
  }

  return 0;
}

