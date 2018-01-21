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

int a[110][110], curr[110], n; 

int main(){
  int ans = -127*100*100;
  int nbst = ans;
  scanf("%d", &n);
  fori(i, 0, n) fori(j, 0, n) scanf("%d", &a[i][j]), nbst = max(nbst, a[i][j]);

  if(nbst <= 0) {
    cout << nbst << endl;
    return 0;
  }

  fori(l, 0, n){

    fori(i, 0, n) curr[i] = 0;

    fori(r, l, n){
      fori(i, 0, n) curr[i] += a[i][r];

      int sum = 0;

      fori(i, 0, n){
        sum += curr[i];
        if(sum < 0) sum = 0;

        ans = max(ans, sum);
      }
    }
  }

  cout << ans << endl;
  return 0;
}

