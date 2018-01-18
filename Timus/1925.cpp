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

int n, k;

int main(){
  scanf("%d%d", &n, &k);
  int des = k-2, curr = 0;
  fori(i, 0, n){
    int a, b;
    scanf("%d%d", &a, &b);
    des += a-2;
    curr += b;
  }

  if(des - curr < 0) cout << "Big Bang!" << endl;
  else cout << (des - curr) << endl;

  return 0;
}

