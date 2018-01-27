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

int n, id, val;

double calc(int id, int val){
  if(id == 1) return 2.0*val;
  if(id == 2) return val*sqrt(2);
  return val;
}

double getmn(int id, int val){
  if(id == 1) return 2.0*val;
  if(id == 2) return val;
  return sqrt(3)*val/2.0;
}

int main(){
  scanf("%d%d", &id, &val);
  double mx = calc(id, val);
  scanf("%d", &n);
  int cnt = 0;
  while(n--){
    scanf("%d%d", &id, &val);
    if(getmn(id, val) <= mx) cnt++;
  }

  cout << cnt << endl;
  return 0;
}

