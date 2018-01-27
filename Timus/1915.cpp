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

int n, x, stk[2000010];

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  bool ok = false;
  while(n--){
    cin >> x;
    if(x > 0){
      stk[++stk[0]] = x;
    }else if(x == -1 && stk[0]){
      cout << stk[stk[0]--] << "\n";
    }else if(x == 0){
      if(2 * stk[0] <= n){
        int sz = stk[0];
        fori(i, 1, sz+1) stk[i+sz] = stk[i];
        stk[0] <<= 1;
      }else if(!ok){
        ok = true;
        int sz = stk[0];
        fori(i, 1, sz+1) stk[i+sz] = stk[i];
        stk[0] <<= 1;
      }
    }
  }
  return 0;
}

