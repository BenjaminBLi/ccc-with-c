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

int n, dx[4] = {1, -1, 2, -2}, dy[4] = {2, -2, 1, -1};
char a, b;

inline bool valid(int r, int c){
  return 0 <= r && r < 8 && 0 <= c && c < 8;
}

int main(){
  scanf("%d", &n);
  while(n--){
    scanf(" %c %c", &a, &b);
    a -= 'a';
    b -= '1';
    int ans = 0;
    fori(i, 0, 4){
      if(i < 2)
        fori(j, 0, 2){
          if(valid(a + dx[i], b + dy[j])) ans++;
        }
      else
        fori(j, 2, 4) {
          if(valid(a + dx[i], b + dy[j])) ans++;
        }
    }

    cout << ans << endl;
  }
  return 0;
}

