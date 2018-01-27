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

const double pi = 3.1415926535;
double v, a, k;

int main(){
  cin >> v >> a >> k;
  if(a == 0) {
    cout << "0.00" << endl;
    return 0;
  }

  double ang = sin(a*pi/90);
  double dist = ang*v*v/10;
  double diff = 0.0015;
  while(v >= 0.001){
    v = v / sqrt(k);
    diff = ang*v*v/10;
    dist += diff;
  }

  printf("%.2f\n", dist);
  return 0;
}

