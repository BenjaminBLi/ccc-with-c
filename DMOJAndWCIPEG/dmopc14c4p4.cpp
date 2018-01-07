#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i <= (int) (en); i++)
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

const int MAXN = 500010;
bool cons[MAXN];
string in, ans = "HAILHYDRA";
int n, m, freq[26];
set<string> poss;

int main(){
  cin >> in >> m;
  n = in.size();

  fori(i, 9, n-1)
    poss.insert(in.substr(i-9, 9));//, cout << in.substr(i-9, 9) <<", ";
  //cout << endl;

  string curr;
  fori(i, 1, m){
    cin >> curr;
    string f = "";
    for(char ch : ans) f += curr[ch-'A'];
    //cout << f << endl;

    if(poss.find(f) != poss.end()){
      f = "";
      fori(i, 1, 26) f[curr[i-1]-'A'] = i-1 + 'A';

      for(char ch : in) cout << f[ch - 'A'];
      return 0;
    }
  }

  cout << "KeyNotFoundError" << endl;
                                                                                                                                                                                                                                            return 0;
}
