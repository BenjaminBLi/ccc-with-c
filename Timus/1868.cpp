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

string medals[3] = {"gold", "silver", "bronze"};
map<string, string> medal;
string c, m, t, s;

int main(){
  fori(i, 0, 3){
    fori(j, 0, 4){
      cin >> c;
      medal[c] = medals[i];
    }
  }

  int n, bst = 0, cnt = 0;
  cin >> n;
  while(n--){
    int c;
    int curr = 0;
    cin >> c;
    while(c--){
      cin >> s >> t >> m;
      if(medal.count(s) && medal[s] == m) curr++; 
    }
    if(curr == bst) cnt ++;
    else if(curr > bst){
      bst = curr;
      cnt = 1;
    }
  }

  cout << cnt*5 << endl;

  return 0;
}

