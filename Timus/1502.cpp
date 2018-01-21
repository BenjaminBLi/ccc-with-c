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

ll n;

int main(){
  scanf("%lld", &n);
  
  ll c = n*(n+1)/2;
  ll cnt = 0;
  fori(i, 0, n+1){
    cnt += c;
    cnt += i * (n-i+1);
    c -= i;
  }
    
  cout << cnt << endl;
  return 0;
}

