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

ii a, b, c;

int main(){
  scanf("%d%d%d%d%d%d", &a.f, &a.s, &b.f, &b.s, &c.f, &c.s);
  printf("%d %d", a.f-c.f, a.s - b.s);
  return 0;
}

