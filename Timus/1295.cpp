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

  int cnt = 0;
  int a, b, c, d;
  for(int i = 10;;i *= 10){
    a = b = c = d = 1;
    rfori(j, n, 1){
      b = (b*2)%i;
      c = (c*3)%i;
      d = (d*4)%i;
    }

    if((a+b+c+d)%i) break;
    cnt++;
  }

  cout << cnt << endl;

  
  return 0;
}

