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

const int MAXN = 1010;
int n;
map<string, int> id;
string c;

void init(){
  id["Alice"] = 1;
  id["Ariel"] = 1;
  id["Aurora"] = 1;
  id["Phil"] = 1;
  id["Peter"] = 1;
  id["Olaf"] = 1;
  id["Phoebus"] = 1;
  id["Ralph"] = 1;
  id["Robin"] = 1;
  id["Bambi"] = 2;
  id["Belle"] = 2;
  id["Bolt"] = 2;
  id["Mulan"] = 2;
  id["Mowgli"] = 2;
  id["Mickey"] = 2;
  id["Silver"] = 2;
  id["Simba"] = 2;
  id["Stitch"] = 2;
  id["Dumbo"] = 3;
  id["Genie"] = 3;
  id["Jiminy"] = 3;
  id["Kuzko"] = 3;
  id["Kida"] = 3;
  id["Kenai"] = 3;
  id["Tarzan"] = 3;
  id["Tiana"] = 3;
  id["Winnie"] = 3;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  init();
  int cpos = 1;
  cin >> n;
  int ans = 0;
  fori(i, 0, n){
    cin >> c;
    ans += abs(cpos - id[c]);
    cpos = id[c];
  }
  cout << ans << endl;
  return 0;
}

