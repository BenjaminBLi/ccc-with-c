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

ll a[200010], ans[200010];

void gen(){
  ll bst = 1;
  a[1] = ans[1] = bst;
  fori(i, 1, 100001){
    a[left(i)] = a[i];
    a[right(i)] = a[i] + a[i+1];
    bst = max(bst, a[i]);
    ans[i] = bst;
  }
}

int main(){
  gen();
  int n;
  scanf("%d",  &n);
  while(n){
    printf("%lld\n", ans[n]); 
    scanf("%d", &n);
  }
  return 0;
}

