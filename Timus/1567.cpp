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
map<char, int> cost;

void gen(){
  for(char c = 'a'; c <= 'z'; c++){
    cost[c] = (c - 'a')%3 + 1;
  }

  cost['.'] = 1;
  cost[','] = 2;
  cost['!'] = 3;
  cost[' '] = 1;
}

int main(){
  gen();
  getline(cin, s);
  int ans = 0;
  for(char ch : s){
    ans += cost[ch];
  }
  cout << endl;
  cout << ans << endl;
  return 0;
}

