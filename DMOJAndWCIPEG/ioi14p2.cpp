#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
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

const int MAXN = 2000010;
int orig[MAXN];

struct node{
	int l, r;
	int add, rem;
	bool flag;
	node(){add = 0, rem = 1<<30, flag = false;}
}tree[MAXN*3];

void build(int l, int r, int idx = 1){
  tree[idx].l = l, tree[idx].r = r;
  if(l == r) return;
  build(l, mid(l, r), left(idx)), build(mid(l, r) + 1, r, right(idx));
}

inline void prop(int idx){
  node &p = tree[idx];
  for(int i = left(idx); i <= right(idx); i++){
    node &c = tree[i];
    c.rem = min(c.rem, p.rem);
    c.rem = max(c.rem, p.add);
    c.add = min(c.add, p.rem);
    c.add = max(c.add, p.add);
  }
}

void upd(int l, int r, int val, int op, int idx = 1){
  node &c = tree[idx];
  if(c.l > r || c.r < l) return;
  if(l <= c.l && c.r <= r){
    if(op == 1){
      c.add = max(c.add, val);
      c.rem = max(c.rem, val);
    }else{
      c.add = min(c.add, val);
      c.rem = min(c.rem, val);
    }
    return;
  }
  prop(idx);
  c.add = 0;
  c.rem = 1<<30;
  upd(l, r, val, op, left(idx));
  upd(l, r, val, op, right(idx));
}

void calc(int idx = 1){
  node &c = tree[idx];
  if(c.l == c.r){
    orig[c.l] = c.add;
  }else{
    prop(idx);
    calc(left(idx)), calc(right(idx));
  }
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  build(0, n-1);
  fori(i, 0, k){
    upd(left[i], right[i], height[i], op[i]);
  }
  calc();
  fori(i, 0, n) finalHeight[i] = orig[i];
}

int cn = 9, ck = 6, ops[MAXN], l[MAXN], r[MAXN], ht[MAXN], en[MAXN];

int main(){
  ops[0] = ops[3] = ops[4] = 1, ops[1] = ops[2] = ops[5] = 2;
  l[0] = 1, l[1] = 4, l[2] = 3, l[3] = 0, l[4] = 2, l[5] = 6;
  r[0] = 8, r[1] = 9, r[2] = 6, r[3] = 5, r[4] = 2, r[5] = 0;
  ht[0] = 4, ht[1] = 1, ht[2] = 5, ht[3] = 3, ht[4] = 5, ht[5] = 0;
  buildWall(cn, ck, ops, l, r, ht, en);
  fori(i, 0, cn) printf("%d, ", en[i]); cout << endl;
  return 0;
}
