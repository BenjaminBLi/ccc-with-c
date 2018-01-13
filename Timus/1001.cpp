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

double c;
vector<double> ans;

int main(){
  while(scanf("%lf", &c) != EOF){
    ans.pb(sqrt(c));
  }
  rfori(i, ans.size()-1, 0) printf("%.04lf\n", ans[i]);
  return 0;
}

