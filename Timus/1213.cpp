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

string c, a, b;
set<string> st;

int main(){

  cin >> c;
  while(cin >> c){
    if(c == "#") break;
    auto pos = c.find_first_of("-", 0);
    b = c.substr(pos+1);
    a = c.substr(0, pos);
    st.insert(a);
    st.insert(b);
  }

  if(st.size() == 0) cout << 0 << endl;
  else  cout << st.size() - 1 << endl;

  return 0;
}

