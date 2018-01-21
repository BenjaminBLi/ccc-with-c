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

string s, key = "Sandro";

int main(){
  int cnt = 12;
  cin >> s;
  fori(i, 0, s.size()-5){
    int curr = 0;
    fori(j, 0, 6) {
      if(isupper(s[i+j]) != isupper(key[j])) curr++;
      if(tolower(s[i+j]) != tolower(key[j])) curr++;
    }
    cnt = min(cnt, curr);
  }
  cout << cnt*5 << endl;
  return 0;
}

