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

vector<ll> primes;
ll n;

int main(){
  scanf("%lld", &n);

  int ans = 0;
  while((n&1) == 0 && ans <= 20){
    ans++;
    n >>= 1;
  }

  ll i;
  for(i = 3; i*i <= n && ans <= 20; i += 2){
    while(n%i == 0){
      ans++;
      n /= i;
    }
  }

  if(n != 1) ans++;

  if(ans == 20) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

