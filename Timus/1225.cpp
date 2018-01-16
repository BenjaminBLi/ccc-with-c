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

//first dim is red, second is blue, third is white
int n;
ll memo[50];

ll solve(int idx){
  ll &curr = memo[idx];
  if(curr != -1) return curr;
  if(idx == 0) return 0;
  if(idx == 1) return 2;
  curr = solve(idx-1) + solve(idx-2);
  return curr;
}

int main(){
  memset(memo, -1, sizeof memo);
  scanf("%d", &n);
  cout << solve(n) << endl;
  return 0;
}

