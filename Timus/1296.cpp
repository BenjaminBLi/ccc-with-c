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

const int MAXN = 60010;
int n;
ll arr[MAXN];

int main(){
  scanf("%d", &n);

  fori(i, 1, n+1){
    scanf("%lld", arr+i);
  }

  ll bst = 0, curr = 0;
  fori(i, 1, n+1){
    curr += arr[i];
    if(curr < 0) curr = 0;
    bst = max(bst, curr);
  }

  cout << bst << endl;

  return 0;
}

