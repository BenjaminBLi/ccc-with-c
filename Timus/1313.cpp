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

int n, a[110][110];

void calc(ii &c){
  if(c.s == 0) c.f++;
  else c.s++;
  if(c.f == n) c = {n-1, 1};
}

int main(){
  scanf("%d", &n);
  fori(i, 0, n) fori(j, 0, n) scanf("%d", &a[i][j]);
  int len = 1;
  ii st = {0, 0};

  for(; len <= n; len++){
    ii c = st;
    fori(i, 0, len){
      printf("%d ", a[c.f][c.s]);
      c.f--;
      c.s++;
    }
    calc(st);
  }

  for(len-=2; len; len--){
    ii c = st;
    fori(i, 0, len){
      printf("%d ", a[c.f][c.s]);
      c.f--;
      c.s++;
    }
    calc(st);
  }


  return 0;
}

