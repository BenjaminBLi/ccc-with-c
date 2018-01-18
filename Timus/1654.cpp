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

string in;
vector<char> stk;

int main(){
  cin >> in;
  stk.pb(in[0]);
  fori(i, 1, in.size()){
    if(stk.size() && stk.back() == in[i]) stk.pop_back();
    else stk.pb(in[i]);
  }
  for(char ch : stk) putchar(ch); putchar('\n');
  return 0;
}

