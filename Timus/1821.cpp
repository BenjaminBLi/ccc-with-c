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
ll h, m, s, t[110];
string name[110];
vector<string> ans;

int main(){
  scanf("%d", &n);
  fori(i, 0, n){
    cin >> name[i];
    scanf("%lld:%lld.%lld", &h, &m, &s);
    t[i] = h*600 + m*10 + s;
  }

  fori(i, 0, n){
    bool ok = true;
    fori(j, 0, n)
      if(t[j] < t[i] && t[j] + 300*j < t[i] + 300*i) ok = false;

    if(ok) ans.pb(name[i]);
    
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(string s : ans) cout << s << endl;

  return 0;
}

