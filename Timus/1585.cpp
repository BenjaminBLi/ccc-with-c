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

map<string, int> id;
int n, a, b, c;
string s, ss;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while(n--){
    cin >> s >> ss;
    if(s[0] == 'E') a++;
    else if(s[0] == 'L') b++;
    else c++;
  }
  int bst = max(a, max(b, c));
  if(bst == a){
    puts("Emperor Penguin");
  }else if(bst == b){
    puts("Little Penguin");
  }else{
    puts("Macaroni Penguin");
  }
  return 0;
}

