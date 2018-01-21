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
char s[110], ans[110];

int main(){
  scanf("%s", s);
  n = strlen(s);

  rfori(i, n-1, 1){
    int curr = s[i] - s[i-1];
    curr %= 26;
    if(curr < 0) curr += 26;

    ans[i] = 'a' + curr;
  }

  int curr = s[0] - 'a' - 5;
  curr %= 26;
  if(curr < 0) curr += 26;

  ans[0] = 'a' + curr;
  puts(ans);

  return 0;
}

