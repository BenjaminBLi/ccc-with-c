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

const ll seed = 131;
string s;
int n;
ll pre[10010], suf[10010], lvl[10010];

int main(){
  cin >> s;
  n = s.size();

  if(n == 1) cout << s << s << endl;

  fori(i, 1, n){
    bool ok = true;
    int en = n-i;
    for(int j = 0; j < en && ok; j++)
      ok = s[i+j] == s[n-j-1];
    if(ok){
      cout << s;
      rfori(j, i-1, 0) putchar(s[j]);
      cout<<endl;
      break;
    }
  }

  return 0;
}

