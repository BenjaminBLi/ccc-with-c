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

int n, a[100010];

int main(){
  scanf("%d", &n);
  fori(i, 0, n) scanf("%d", a+i);
  int curr = 0, cnt = 0, bst = 0, bcnt = 0;
  fori(i, 1, n){
    cnt++;
    if(cnt > bcnt){
      bst = curr;
      bcnt = cnt;
    }
    if(a[curr]> a[i]){
      curr = i;
      cnt = 1;
    }
   
  }
  cout << (bst+1) <<endl;//<< ", " << bcnt << endl;
  return 0;
}

