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
map<int, int> cnt;

int main(){
  int ans = 0;
  scanf("%d", &n);
  while(n--){
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }
  for(auto it : cnt) ans += it.s/4;
  cout << ans << endl;
  return 0;
}

