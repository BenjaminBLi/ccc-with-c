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

string s;
int carry = 0;

int main(){
  cin >> s;
  int sz = (s.size()+1)/2;
  string a = s.substr(0, sz), b = s.substr(sz - (s.size()&1), sz);

  reverse(a.begin(), a.end());

  if(a < b){
    fori(i, 0, sz+1){
      a[i]++;
      if(a[i] == '0'+10) a[i] = '0';
      else break;
    }
  }

  reverse(a.begin(), a.end());
  cout << a;
  reverse(a.begin(), a.end());
  if(s.size()&1) cout << a.substr(1) << endl;
  else cout << a << endl;

  return 0;
}

