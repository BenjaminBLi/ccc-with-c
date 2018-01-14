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

int a[3];

int main(){
  scanf("%d%d%d", &a[0], &a[1], &a[2]);
  sort(a, a+3);
  cout << min((a[0] - (a[1]*a[2])), a[0] - a[1] - a[2]) << endl;
  return 0;
}

