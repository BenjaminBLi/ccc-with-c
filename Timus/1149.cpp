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
char on = '-', off = '+';

inline void curr(int mx){
  fori(i, 1, mx+1){
    printf("sin(%d", i);
    if(i != mx){
      printf("%c", on);
      swap(on, off);
    }
  }
  on = '-', off = '+';
  fori(i, 0, mx) printf(")");
}

int main(){
  scanf("%d", &n);
  fori(i, 1, n) printf("(");
  fori(i, 1, n+1){
    curr(i);
    if(i != n)printf("+%d)", n-i+1);
    else printf("+%d", 1);
  }
  cout << endl;
  return 0;
}

