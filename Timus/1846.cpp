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

struct node{
  int l, r;
  int val;
  node(){val = 0;}
  void apply(int a);
  void calc();
  void upd(int idx, int val);
  void build(int l, int r);
  node *left, *right;
}root;

void node::build(int cl, int cr){
  l = cl, r = cr;
  if(l == r){
    return;
  }
  left = new node();
  right = new node();
  left->build(cl, mid(cl, cr)), right->build(mid(cl, cr)+1, cr);
}

void node::apply(int c){
  val = c;
}

void node::calc(){
  val = __gcd(left->val, right->val);
}

void node::upd(int pt, int p){
  if(pt <= l && r <= pt){
    apply(p);
    return;
  }else if(r < pt || pt < l) return;
  left->upd(pt, p), right->upd(pt, p);
  calc();
}

const int MAXN = 100010;
int n, x, gcd[MAXN];
char ch;
set<ii> vals;

void add(int val, int idx){
  vals.insert(ii(val, idx));
  root.upd(idx, val);
}

void rem(int val, int idx){
  auto it = vals.upper_bound(ii(val, idx));
  it--;
  root.upd(it->s, 0);
  vals.erase(it);
}

int main(){
  scanf("%d", &n);
  root.build(1, n);

  fori(i, 1, n+1){
    scanf(" %c%d", &ch, &x);
    switch(ch){
      case '+':
        add(x, i);
        break;
      case '-':
        rem(x, i);
        break;
    }

    printf("%d\n", root.val == 0 ? 1 : root.val);
  }
  return 0;
}

