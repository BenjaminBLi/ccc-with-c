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

int n, a[1010], r;

int main(){
  scanf("%d%d", &n, &r);
  fori(i, 0, n) scanf("%d", a+i);
  fori(i, 0, 10) printf("%d", a[(i+r)%n]);cout<<endl;
  return 0;
}

