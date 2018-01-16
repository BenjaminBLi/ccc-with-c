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

ii st;
int n, a[110][110];

void nxt(){
  if(st.f) st.f++;
  else{
    st.s--;
    if(st.s < 0) st = {1, 0};
  }
}

int main(){
  scanf("%d", &n);
  st = {0, n-1};
  int cnt = 1;
  fori(i, 1, n+1){
    //i is the length of the current array
    ii c = st;
    fori(j, 0, i){
      a[c.f][c.s] = cnt++;
      c.f++;
      c.s++;
    }
    nxt();
  }
  rfori(i, n-1, 1){
    ii c = st;
    fori(j, 0, i){
      a[c.f][c.s] = cnt++;
      c.f++;
      c.s++;
    }
    nxt();
  }

  fori(i, 0, n){
    fori(j, 0, n) printf("%d ", a[i][j]);
    printf("\n");
  }
  return 0;
}

