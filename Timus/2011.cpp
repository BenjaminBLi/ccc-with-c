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

const int MAXN = 110;
int n;
vi c;

int main(){
  scanf("%d", &n);
  for(int i = 0, x; i < n; i++){
    scanf("%d", &x);
    c.pb(x);
  }
  sort(c.begin(), c.end());
  

  int cnt = 0;
  do{
    cnt++;
  }while(cnt < 6 && next_permutation(c.begin(), c.end()));


  if(cnt >= 6) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

