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

map<int, int> freq;
int n;

int main(){
  scanf("%d", &n);
  for(int i = 0, x; i < n; i++){
    scanf("%d", &x);
    freq[x]++;
  }

  int bst = 0, ans = 0;
  for(auto it : freq) if(it.s > bst) bst = it.s, ans = it.f;
  cout << ans << endl;
  return 0;
}

