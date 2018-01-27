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

ll n, m;

int main(){
  cin >> n >> m;
  n *= 3;
  ll c = 0, x;
  int cnt = 0;
  while(m--){
    cin >> x;
    cnt++;
    c += x;
    if(c > n){
      cout << "Free after " << cnt << " times." << endl;
      return 0;
    }
  }

  cout << "Team.GOV!" << endl;

  return 0;
}

