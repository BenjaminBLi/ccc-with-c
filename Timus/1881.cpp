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

int h, w, n;
string a;

int main(){
  int cpos = 0, cnt = 1;
  cin >> h >> w >> n;
  while(n--){
    cin >> a;
    int sz = a.size();
    if(cpos == 0) cpos = sz;
    else if(cpos + sz + 1 <= w) cpos += sz + 1;
    else{
      cnt++;
      cpos = sz;
    }
    //cout << a << ": " << cpos << ", " << cnt << endl;
  }
  //cout << cnt << endl;
  cout << ((cnt + h - 1)/h) << endl;
  return 0;
}

