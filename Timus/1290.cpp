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

const int MAXN = 25010;
int n, p[MAXN];

int main(){
  scanf("%d", &n);
  n <<= 1;
  int a = 0, p = 0;
  for(int i = 1; i*i <= n; i++){
    if(n%i == 0){
      int k = n/i;

      int curr = n/i - i + 1;
      if(curr > 0 && (curr&1) == 0) p = max(p, i);

      curr = n/k - k + 1;
      if(curr > 0 && (curr&1) == 0) p = max(p, k);
    }
  }
  cout << ((n/p - p + 1)/2) << " " << p << endl;
  return 0;
}

