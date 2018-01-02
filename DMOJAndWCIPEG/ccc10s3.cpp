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

const int circ = 1000000;
int h, a[1010], k;

bool valid(int gap){
  int best = circ;
  int diam = gap*2;
  int x = 0;
  while(x < h && a[x] <= a[0] + diam){
    int curr = 1, y = x+1;
    int back = a[x];
    while(y < h && a[y] + diam - circ < a[x]){
      if(a[y] > back){
        back = a[y] + diam;
        curr++;
      }
      y++;
    }
    best = min(curr, best);
    x++;
  }
  return best <= k;
}

int main(){
  scanf("%d", &h);
  fori(i, 0, h) scanf("%d", a+i);
  sort(a, a+h);
  scanf("%d", &k);

  int lo = 0, hi = 1000000, mid, ans = 1000000;
  
  while(lo <= hi){
    mid = ((hi+lo)>>1);
    if(valid(mid)){
      ans = min(ans, mid);
      hi = mid-1;
    }else lo = mid+1;
  }
  
  cout << ans << endl;
  return 0;
}

