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

int n, k, a[110], ans[110][110];

int main(){
  scanf("%d%d", &n, &k);
  fori(i, 0, n) scanf("%d", a+i);

  int len = (n+k-1)/k, cnt = 0;

  memset(ans, -1, sizeof ans);
  for(int c = 0; c < k && cnt < n; c++){
    for(int r = 0; r < len && cnt < n; r++)
      ans[r][c] = a[cnt++];
  }

  fori(r, 0, len){
    fori(c, 0, n) if(ans[r][c] != -1)
      printf("%4d", ans[r][c]);
    printf("\n");
  }

  return 0;
}

