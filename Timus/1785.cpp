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

int main(){
  scanf("%d", &n);
  if(1 <= n && n <= 4) printf("few\n");
  else if(n <= 9) printf("several\n");
  else if(n <= 19) printf("pack\n");
  else if(n <= 49) printf("lots\n");
  else if(n <= 99) printf("horde\n");
  else if(n <= 249) printf("throng\n");
  else if(n <= 499) printf("swarm\n");
  else if(n <= 999) printf("zounds\n");
  else  printf("legion\n");
  return 0;
}

