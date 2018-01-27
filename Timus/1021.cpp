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

const int MAXN = 50010;
int n, k, a[MAXN], b[MAXN];

int main(){
  memset(a, 0x3f3f3f, sizeof a);
  memset(b, 0x3f3f3f, sizeof b);
  scanf("%d", &n);
  fori(i, 0, n) scanf("%d", a+i);
  scanf("%d", &k);
  fori(i, 0, k) scanf("%d", b+i);
  reverse(b, b+k);
  int target = 10000;
  fori(i, 0, n){
    int val = *lower_bound(b, b+k, target-a[i]);
    if(val + a[i] == target){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}

