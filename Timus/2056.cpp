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

int n, cnt[10];

int main(){
  double avg = 0;
  scanf("%d", &n);
  for(int i = 0, x; i < n; i++){
    scanf("%d", &x);
    avg += x;
    cnt[x]++;
  }
  if(cnt[3] != 0) printf("None\n");
  else if(cnt[5] == n) printf("Named\n");
  else if(avg >= 4.5*n && cnt[3] == 0) printf("High\n");
  else if(cnt[3] == 0) printf("Common\n");
  else printf("None\n");
  return 0;
}

