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
set<int> val;

void gen(){
  int inc = 1, curr = 1;
  val.insert(curr);
  while(curr >= 0){
    curr += inc++;
    val.insert(curr);
  }
}

int main(){ gen();
  scanf("%d", &n);
  fori(i, 0, n){
    int a;
    scanf("%d", &a);
    if(val.count(a)) printf("%d ", 1);
    else printf("%d ", 0);
  }
  return 0;
}

