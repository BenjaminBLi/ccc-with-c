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
vector<string> strs;
string c;

int main(){
  cin >> n;
  while(n--) {
    cin >> c;
    strs.pb(c);
  }
  cin >> c;
  for(string a : strs){
    if(a[0] == c[0]) cout << a << endl;
  }
  return 0;
}

