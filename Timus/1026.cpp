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
int n, k, a[MAXN];
string s;

int main(){
  scanf("%d", &n);
  fori(i, 0, n) scanf("%d", a+i);
  sort(a, a+n);
  cin >> s;
  scanf("%d", &k);
  while(k--){
    int rnk;
    scanf("%d", &rnk);
    rnk--;
    printf("%d\n", a[rnk]);
  }
  return 0;
}

