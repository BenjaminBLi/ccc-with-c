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

int n1, c1, n2, t, c2, n3, n, h, m;

int main(){
  scanf("%d%d%d%d%d%d", &n1, &c1, &n2, &t, &c2, &n3);
  scanf("%d", &n);
  int tot = 0;
  while(n--){
    scanf("%d:%d", &h, &m);
    if(h == 0 && m <= 6) continue;
    tot += h + (m + 59)/60;
  }

  printf("Basic:     %d\nCombined:  %d\nUnlimited: %d\n", n1 + c1*tot, n2 + max(0, tot-t)*c2, n3);
  return 0;
}

