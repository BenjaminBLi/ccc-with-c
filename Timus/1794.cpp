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

const int MAXN = 100010;
int n, x, a[MAXN<<1];

int main(){
  scanf("%d", &n);
  fori(i, 0, n){
    scanf("%d", &x);
    a[(i - x+1 + n)%n]++;
  }
  //literally just fucking check every combo and see if it's valid.
  int ans = -1, cnt = 0;
  fori(st, 0, n){
    if(a[st] > cnt){
      ans = st+1;
      cnt = a[st];
    }
  }
  cout << ans << endl;
  return 0;
}

