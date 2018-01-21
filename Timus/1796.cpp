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

int n, freq[6], cost[6] = {10, 50, 100, 500, 1000, 5000};

int main(){
  int tot = 0;
  fori(i, 0, 6) {
    scanf("%d", &freq[i]);
    tot += cost[i]*freq[i];
  }
  scanf("%d", &n);
  int cnt = tot/n;

  int i = 0;
  for(; i < 6 && freq[i] == 0; i++);

  int mn = (tot - cost[i]) % n;
  mn += cost[i] - n;
  int diff = mn/n;

  cout << diff+1 << endl;
  rfori(j, diff, 0){
    cout << cnt - j << " ";
  }
  cout << endl;

  return 0;
}

