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

const int MAXN = 110;
int n, t;
string id;
ii a[MAXN];

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int a = 2, b = 10;
  fori(i, 0, n){
    cin >> t >> id;
    if(id == "hungry") a = max(a, t);
    else b = min(b, t);
  }

  if(a >= b) puts("Inconsistent");
  else cout << b << endl;
  return 0;
}

