#include <bits/stdc++.h>
#include <bits/extc++.h>
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

const int MAXN = 1010; int memo[MAXN][MAXN];

void gen(int l, int r){ 
  if(l == r) return;
  int m = mid(l, r);
  
  //generate all intervals [i, m]: l <= i < m and [m, i]: m < i <= r
  rfori(i, m-1, l)
    memo[i][m] = Secret(memo[i][i], memo[i+1][m]);
  fori(i, m+2, r+1)
    memo[m+1][i] = Secret(memo[m+1][i-1], memo[i][i]);

  gen(l, m), gen(m+1, r);
}

int Query(int l, int r){
  if(l == r) return memo[l][r];
  int cr = r;
  while(cr && (memo[l][cr] == -1 || memo[cr+1][r] == -1)) cr--;
  //first interval where [l, cr] has a value
  if(cr == r) return memo[l][r];
  else return Secret(memo[l][cr], memo[cr+1][r]);
}

void Init(int N, int* A){
  memset(memo, -1, sizeof memo);
  fori(i, 0, N) memo[i][i] = A[i];
  gen(0, N-1);
}

