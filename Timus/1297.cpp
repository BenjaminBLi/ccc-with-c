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
int st = -1, len = 0;

int main(){
  cin >> s;
  fori(i, 0, s.size()){
    int cl = 0;

    //odd-numbered palindromes
    while(i+cl < s.size() && i-cl >= 0 && s[i+cl] == s[i-cl]) {
      if((cl<<1|1) > len){
        len = cl<<1|1;
        st = i-cl;
      }
      cl++;
    }

    //even-numbered palindromes
    cl = 0;
    if(i == 0) continue;
    int l = i-1, r = i;
    while(l-cl >= 0 && r+cl < s.size() && s[l-cl] == s[r+cl]){
      if(((cl+1)<<1) > len){
        len = (cl+1)<<1;
        st = l-cl;
      }
      cl++;
    }
  }
  cout << s.substr(st, len) << endl;
  return 0;
}

