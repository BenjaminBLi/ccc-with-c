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

int n, m, y;

bool qpow(int base, int exp, int  mod){
  ll res = 1;
  while(exp){
    if(exp & 1) res = (res*base)%mod;
    exp >>= 1;
    base = (base * base)%mod;
  }
  return (res%mod) == y;
}

int main(){
  scanf("%d%d%d", &n,&m,&y);

  int cnt = 0;
  fori(i, 0, m)
    if(qpow(i, n, m)) cnt++, printf("%d ", i);
  if(cnt == 0) cout << -1 << endl;
  cout << endl;
  return 0;
}

