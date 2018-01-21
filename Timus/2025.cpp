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

int t, n, k, a[10010];

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &n, &k);

    int sz = n/k;
    int rem = n%k;

    fori(i, 0, rem) a[i] = sz+1;
    fori(i, rem, k) a[i] = sz;

    int ans = 0;
    fori(i, 0, k-1) fori(j, i+1, k) ans += a[i]*a[j];
    cout << ans << endl;
  }
  return 0;
}

