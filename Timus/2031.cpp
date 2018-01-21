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

int main(){
  scanf("%d", &n);
  if(n == 1) puts("01");
  else if(n == 2) puts("11 01");
  else if(n == 3) puts("16 06 68");
  else if(n == 4) puts("16 06 68 88");
  else puts("Glupenky Pierre");
  return 0;
}

