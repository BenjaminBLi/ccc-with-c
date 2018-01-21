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

int n, x, mpos = 1<<30, mneg = -(1<<30);

int main(){
  scanf("%d%d", &n, &x);
  while(n--){
    int c;
    scanf("%d", &c);
    if(c < 0) mneg = max(mneg, c);
    else mpos = min(mpos, c);
  }
  if(x > mpos || x < mneg) puts("Impossible");
  else {
    if(x > 0){
      printf("%d %d\n", x, abs(mneg)*2 + x);
    }else{
      printf("%d %d\n", mpos*2 + abs(x), abs(x));
    }
  }
  return 0;
}

