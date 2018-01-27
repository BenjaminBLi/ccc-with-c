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

const int MAXN = 100010;
int n, m, a[MAXN], b[MAXN];

int main(){
  scanf("%d%d", &n, &m);
  fori(i, 0, n) scanf("%d", a+i);
  fori(i, 0, m) scanf("%d", b+i);

  int rmn = min(a[0], b[m-1]);
  int cmn = min(a[n-1], b[0]);
  int ans = max(rmn, cmn);

  int amn = min(a[0], a[n-1]);
  int bmn = min(b[0], b[m-1]);

  fori(i, 1, n){
    //consider taking middle column while traversing
    ans = max(ans, min(a[i], bmn)); 
  }

  fori(i, 1, m){
    //consider taking middle row
    ans = max(ans, min(b[i], amn));
  }

  cout << ans << endl;
  return 0;
}

