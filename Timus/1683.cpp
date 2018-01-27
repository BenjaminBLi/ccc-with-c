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
vector<int> ans;

int main(){
  cin >> n;

  while(n > 1) ans.pb((n)/2), n = (n+1)/2;
  cout << ans.size() << endl;
  for(int p : ans) cout << p << " ";cout<<endl;

  return 0;
}

