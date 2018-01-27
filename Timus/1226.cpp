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

string line, c;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int len;
  while(getline(cin, line)){
    len = line.size();
    int l = 0, r = 0;
    while(r < len){
      while(r < len && isalpha(line[r])) r++;
      rfori(i, r-1, l) cout << (line[i]);
      l = r;
      while(l < len && !isalpha(line[l])){
        cout << line[l];
        l++;
      }
      r = l;
    }
    cout << endl;
  }
  return 0;
}

