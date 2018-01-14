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

int n, k;

int main(){
  scanf("%d%d", &n, &k);

  //number of steaks with one side cooked, see how many totally uncooked need to be cooked, that's the ans
  if(n <= k) cout << 2 << endl;
  else cout << (n*2/k) + (n*2%k ? 1 : 0) << endl;

  return 0;
}

