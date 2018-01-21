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

const int MAXN = 100010;
int n;
ii c[MAXN];

bool cmp(ii a, ii b){
  if(a.s != b.s) return a.s < b.s;
  return a.f > a.s;
}

int main(){
  scanf("%d", &n);
  fori(i, 0, n){
    scanf("%d%d", &c[i].f, &c[i].s);
  }
  sort(c, c+n, cmp);
  int cnt = 0, en = 0;
  fori(i, 0, n){
    if(c[i].f > en){
      en = c[i].s;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

