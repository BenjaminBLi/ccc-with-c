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

int n, a[110];
double tot = 0;
vector<double> curr;

int main(){
  scanf("%d", &n);
  double x;
  for(int i = 0; i < n; i++){
    scanf("%lf", &x);
    curr.pb(x);
  }
  sort(curr.begin(), curr.end());
  while(curr.size() > 1){
    double a = curr.back();
    curr.pop_back();
    double b = curr.back();
    curr.pop_back();
    curr.pb(2*sqrt(a*b));
  }


  printf("%.02lf\n", curr[0]);

  return 0;
}

