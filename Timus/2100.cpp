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
string c;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  string key = "+one";
  int cnt = 2;
  while(n--){
    cin >> c;
    if(c.find(key) != string::npos) cnt++;
    cnt++;
  }
  if(cnt == 13) cnt++;
  cout << cnt*100 << endl;
  return 0;
}

