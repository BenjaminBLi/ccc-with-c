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

int a, b, c, d;

int main(){
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if(a <= c){
    int ans;
    while(a <= c){
      if(a + b <= c){
        a += b;
        ans = a;
      }else{
        ans = c;
        break;
      }

      if(c - d >= a){
        c -= d;
        ans = c;
      }else{
        ans = a;
        break;
      }
    }
    cout << ans << endl;
  }else cout << a << endl;
  return 0;
}

