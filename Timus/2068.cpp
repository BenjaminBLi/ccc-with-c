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
  scanf("%d", &n);
  bool ok = true;
  while(n--){
    int x; scanf("%d", &x);

    if(x/2%2 == 0) ok = !ok;
  }

  if(ok) cout << "Daenerys" << endl;
  else cout << "Stannis" << endl;
  return 0;
}

