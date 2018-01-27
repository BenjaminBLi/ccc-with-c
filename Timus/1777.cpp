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
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

ll a, b, c;

int main(){
  cin >> a >> b >> c;
  vector<ll> stones{a, b, c};

  set<ll> diff{abs(a-b), abs(b-c), abs(a-c)};

  ll cnt = 1;

  while(*diff.begin() != 0){
    cnt++;
    ll mn = *diff.begin();
    for(ll c : stones)
      diff.insert(abs(c-mn));
    stones.pb(mn);
  }

  cout << cnt << endl;


  return 0;
}

