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
int cnt[51];

int main(){
  cin >> s;
  int n = s.size();
  int pos = 0;
  fori(st, 0, n){
    fori(i, 0, n){
      if(s[st] == s[i]) {
        cnt[st]++;
        if(cnt[pos] < cnt[st]) pos = st;
      }
    }
  }
  cout << s.substr(pos, 1)<< endl;
  return 0;
}

