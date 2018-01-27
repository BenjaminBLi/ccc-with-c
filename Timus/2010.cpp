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

int n, x, y;

inline bool valid(int x, int y){
  return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main(){
  scanf("%d%d%d", &n, &x, &y);

  ll rook = 2*n-2;
  ll bishop = 0;
  ll king = 0;
  ll knight = 0;
  ll queen;

  bishop += min(n-x, n-y);
  bishop += min(x-1, n-y);
  bishop += min(x-1, y-1);
  bishop += min(n-x, y-1);

  queen = bishop+rook;

  for(int i = -1; i <= 1; i++) for(int j = -1; j <= 1; j++){
    if((i || j) && valid(x + i, y + j)){
      king++;
    }
  }

  for(int i = -2; i <= 2; i++) for(int j = -2; j <= 2; j++){
    if(abs(i) + abs(j) == 3 && valid(x + i, y + j)){
      knight++;
    }
  }

  printf("King: %lld\nKnight: %lld\nBishop: %lld\nRook: %lld\nQueen: %lld",king,knight,bishop,rook,queen);

  return 0;
}

