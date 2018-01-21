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

string ans;
int bst = 1<<30, adj[6][6];

void solve(int idx, int mask, int dst, string s){
  if(mask == ((1<<5)-1) && idx == 4){
    if(bst > dst){
      bst = dst;
      ans = s;
    }
    return;
  }

  fori(i, 0, 5){
    if(mask & (1<<i)) continue;
    if(__builtin_popcount(mask) == 3 && i == 2) continue;
    solve(i, mask|(1<<i), dst + adj[idx][i], s + " " + ((char) ('0' + i + 1)));
  }
}

int main(){
  fori(i, 0, 5) fori(j, 0, 5) scanf("%d", &adj[i][j]);

  string a;
  a = (char) ('0'+1);
  solve(0, 1, 0, a);

  cout << bst << "\n" << ans << endl;
  return 0;
}

