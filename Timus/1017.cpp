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
ll memo[510][510];

ll solve(int prev, int rem){
  if(rem == 0) return 1;
  if(rem <= prev) return 0;

   ll &ret = memo[prev][rem];
   if(ret != -1) return ret;

   ret = 0;
   fori(i, prev+1, rem+1) ret += solve(i, rem-i);

   return ret;
}

void reset(){
  fori(i, 0, 510) fori(j, 0, 510) memo[i][j] = -1;
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    reset();
    printf("%lld\n", solve(0, n)-1);
  }
  return 0;
}

