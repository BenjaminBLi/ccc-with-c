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
  vi ans;
  scanf("%d", &n);
  int x;
  scanf("%d", &x);
  int cnt = 1, val = x; 
  for(int i = 1, c; i < n; i++){
    scanf("%d", &c);
    if(c != val){
      ans.pb(cnt);
      ans.pb(val);
      val = c;
      cnt = 1;
    }else cnt++;
  }
    ans.pb(cnt);
    ans.pb(val);

  for(int v : ans){
    printf("%d ", v);
  }
  
  return 0;
}

