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

int n, m, a[10010];

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0, x; i < m; i++){
    scanf("%d", &x);
    a[x]++;
  }
  fori(i, 1, n+1){
    printf("%.02lf%\n", 100.0*a[i]/m);
  }
  return 0;
}

