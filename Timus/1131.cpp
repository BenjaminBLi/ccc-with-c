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

int k, n;
int solve(int rem, int curr){
  if(rem <= 0) return 0;
  if(curr == k)
    return (rem + k - 1) / k;

  return 1 + solve(rem - curr, min(k, curr*2));
}

int main(){
  scanf("%d%d", &n, &k);
  printf("%d\n", solve(n-1, 1));
  return 0;
}

