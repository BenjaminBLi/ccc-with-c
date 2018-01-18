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

string c;

inline bool valid(int mod){
  int curr = 0;
  int val, mx = 0;
  fori(i, 0, c.size()){
    if('A' <= c[i] && c[i] <= 'Z') val = c[i] - 'A' + 10;
    else val = c[i] - '0';
    mx = max(val, mx);
    curr = (curr*mod + val)%(mod-1);
  }
  return curr%(mod-1) == 0 && mx < mod;
}

int main(){
  cin >> c;

  int ans = -1;
  fori(i, 2, 37){
    if(valid(i)) {
      ans = i;
      break;
    }
  }

  if(ans == -1) cout << "No solution." << endl;
  else  cout << ans << endl;
  return 0;
}

