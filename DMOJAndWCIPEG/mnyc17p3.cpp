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

const int seed = 131, MAXN = 1000010;
ll pre[MAXN], suf[MAXN], base[MAXN];
string a, b;
int n, m;

int main(){
  cin >> a >> b;
  n = a.size(), m = b.size();

  //hash string a from the back and string b from the front, then compare hashes
  pre[0] = b[0];
  base[0] = 1;
  fori(i, 1, m) pre[i] = pre[i-1]*seed + b[i], base[i] = base[i-1]*seed;;
  suf[0] = a[n-1];
  fori(i, 1, n) suf[i] = suf[i-1]+ a[n-1-i]*base[i];

  int i = -1;
  fori(j, 0, min(n, m))
    if(pre[j] == suf[j]) i = j;

  if(i == -1) cout << a << b << endl;
  else cout << a.substr(0, n-i-1) << b.substr(0, m) << endl;

  return 0;
}

