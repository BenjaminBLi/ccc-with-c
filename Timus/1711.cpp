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
pair<string, int> strs[60];
vector<string> ans, sorted;

int main(){
  scanf("%d", &n);
  fori(i, 0, 3*n){
    cin >> strs[i].f; 
    strs[i].s = i/3 + 1;
  }
  sort(strs, strs+3*n);
  fori(i, 0, n){
    int x;
    cin >> x;
    fori(j, 0, 3*n){
      if(strs[j].s == x && (ans.size() == 0 || strs[j].f > ans.back())){
        ans.pb(strs[j].f);
        sorted.pb(strs[j].f);
        break;
      }
    }
  }

  if(ans.size() == n){
    for(string s : ans) cout << s << "\n";
  }else cout << "IMPOSSIBLE\n";
  return 0;
}
