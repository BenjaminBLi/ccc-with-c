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

int m, n, k;

int main(){
  scanf("%d%d%d", &m, &n, &k);
  fori(l, k, 10001){
    int ncnt = 0;
    for(int i = 1; i*i <= l; i++)
      if(l%i == 0) 
        ncnt++;

    int mcnt = 0;
    for(int i = 1; i*i <= l-k; i++)
      if((l-k)%i == 0)
        mcnt++;

    if(ncnt == n && mcnt == m){
      printf("%d\n", l);
      return 0;
    }
  }
  printf("0\n");
  return 0;
}

