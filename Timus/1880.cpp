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

int n, a[4010];
map<int ,int> id;

int main(){
  fori(t, 0, 3){
    scanf("%d", &n);
    int c;
    fori(i, 0, n) {
      scanf("%d", &c);
      id[c]++;
    }
  }
  int cnt = 0;
  for(ii a : id) {
    if(a.s == 3) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

