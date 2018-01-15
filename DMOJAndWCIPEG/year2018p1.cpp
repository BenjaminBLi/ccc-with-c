#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

ll h, m, s;

int main(){
  scanf("%lld%lld%lld", &h, &m, &s);
  m += s/60;
  if(s%60) m++;
  h += m/60;
  if(m%60) h++;
  s %= 60;
  m %= 60;
  h %= 12;

  h = 12-h;
  m = 60-m;
  s = 60-s;

  if(s == 60) s = 0;
  if(m == 60) m = 0;
  //if(h == 0) h = 12;

  printf("%02lld:%02lld:%02lld\n", h, m, s);
  return 0;
}

