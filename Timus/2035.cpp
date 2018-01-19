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

int x, y, c;

int main(){
  cin >> x >> y >> c;
  if(x + y < c) puts("Impossible");
  else {
    int diff = x + y - c;
    if(diff > x) diff -= x, x = 0, y -= diff;
    else x -= diff;
    printf("%d %d\n", x, y);
  }
  return 0;
}

