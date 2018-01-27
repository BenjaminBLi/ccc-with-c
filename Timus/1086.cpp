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

const int MAXN = 1000010;
bool nprime[MAXN];
vi primes;

void gen(){
  for(int i = 2; i*i < MAXN; i++){
    if(!nprime[i])
      for(int j = i+i; j < MAXN; j += i) 
        nprime[j] = true;
  }

  fori(i, 2, MAXN) {
    if(!nprime[i]) {
      primes.pb(i);
    }
  }
}

int n, x;

int main(){
  gen();
  scanf("%d", &n);
  fori(i, 0, n){
    scanf("%d", &x);
    cout << primes[x-1] << endl;
  }
  return 0;
}

