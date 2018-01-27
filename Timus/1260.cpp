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

ll memo[60];

int n;

int main(){
  scanf("%d", &n);
  memo[1] = memo[2] = 1;
  memo[3] = 2;
  fori(i, 4, n+1) memo[i] = memo[i-1] + memo[i-3] + 1;
  cout << memo[n] << endl;
  return 0;
}

