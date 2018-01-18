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

int t1, t2, x;

int main(){
  scanf("%d%d", &t1, &t2);
  int t = 0;
  fori(i, 0, 10){
    scanf("%d", &x);
    t += x*20;
  }

  if(t1 <= t2-t) printf("No chance.\n");
  else printf("Dirty debug :(\n");
  return 0;
}

