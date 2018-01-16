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
  int rem = 0, alive = 0;
  scanf("%d%d", &n, &k);
  while(n--){
    int x;
    scanf("%d", &x);
    alive += max(0, k-x);
    rem += max(0, x-k);
  }
  cout << rem << " " << alive << endl;
  return 0;
}

