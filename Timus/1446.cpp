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
map<string, int> id;
string rev[4] = {"Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw"};
string line;
vector<string> house[4];
string ch, name;

void prnt(int i){
  cout << rev[i] << ":\n";
  for(string &n : house[i]) cout << n << "\n";
  cout << "\n";
}

int main(){
  cin >> n;
  id["Slytherin"] = 0;
  id["Hufflepuff"] = 1;
  id["Gryffindor"] = 2;
  id["Ravenclaw"] = 3;

  getline(cin, line);
  fori(i, 0, n){
    getline(cin, name);
    getline(cin, ch);
    house[id[ch]].pb(name);
  }

  fori(i, 0, 4) prnt(i);
  
  return 0;
}

