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

unordered_map<int, set<int>> vals;
int n;

int main(){
  scanf("%d", &n);
  for(int i = 1, x; i <= n; i++){
    scanf("%d", &x);
    vals[x].insert(i);
  }

  int q, l, r, c;
  scanf("%d", &q);
  fori(i, 0, q){
    scanf("%d%d%d", &l, &r, &c);
    auto it = vals[c].lower_bound(l);
    if(it == vals[c].end() || *it > r) putchar('0');
    else putchar('1');
  }
  
  
  return 0;
}

