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
set<string> id;
string c;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  getline(cin, c);

  int ans = 0;
  fori(i, 0, n){
    getline(cin, c);
    if(id.count(c)) {
      ans++;
    }
    id.insert(c);
  }
  cout << ans << endl;
  return 0;
}

