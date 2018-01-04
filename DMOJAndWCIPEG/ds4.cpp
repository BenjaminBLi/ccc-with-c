#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;
typedef unsigned long long ull;

struct node{
  int val, p, sz;
  node *l, *r;
  int rand32(){
    return rand() & 0xffff << 15 | rand() & 0xffff;
  }

  node(int i) : val(i), sz(1), p(rand32()){l= 0, r = 0;}

  ~node(){free(l); free(r);}
};

inline int sz(node *n){
  return n ? n->sz : 0;
}

inline void upd_sz(node *n){
  if(n) n->sz = sz(n->l) + 1 + sz(n->r);
}

void split(node* n, node* &l, node* &r, int key){
  if(!n) l = r = NULL;
  else if(n->val <= key) split(n ->r, n->r, r, key), l = n;
  else split(n->l, l, n->l, key), r = n;
  upd_sz(n);
}

void merge(node* &n, node* l, node* r){
  if(!l || !r) n = l ? l : r;
  else if(l->p > r->p) merge(l->r, l->r, r), n=l;
  else merge(r->l, l, r->l), n=r;
  upd_sz(n);
}

void insert(node* &n, node* i){
  if(!n) n = i;
  else if(i->p > n->p) split(n, i->l, i->r, i->val), n=i;
  else insert(n->val <= i->val ? n->r : n->l, i);
  upd_sz(n);
}

void erase(node* &n, int val){
  if(!n) return;
  else if(n->val == val){
    node* tmp = n;
    merge(n, n->l, n->r);
    free(tmp);
  }else erase(n->val < val ? n->r : n->l, val);
  upd_sz(n);
}

int rnk(node* n, int val, int idx = 0){
  if(!n) return -1;
  if(n->val == val){
    int o = rnk(n->l, val, idx);
    if(~o) return o;
    else return idx + sz(n->l) + 1;
  }
  if(n->val < val) return rnk(n->r, val, idx+ sz(n->l) + 1);
  else return rnk(n->l, val, idx);
}

int select(node* n, int rnk){
  if(!n) return -1;
  int lsz = sz(n->l) + 1;
  if(lsz == rnk) return n->val;
  else if(lsz < rnk) return select(n->r, rnk-lsz);
  else return select(n->l, rnk);
}

void inorder(node* n){
  if(!n) return;
  inorder(n->l);
  printf("%d ", n->val);
  inorder(n->r);
}

int n, m, ans;
node* root = 0;
int main(){
  scanf("%d%d", &n, &m);
  fori(i, 0, n){
    int a;
    scanf("%d", &a);
    insert(root, new node(a));
  }

  char ch;
  int a;
  ans = 0;
  while(m--){
    scanf(" %c%d", &ch, &a);
    a ^= ans;
    if(ch == 'I') insert(root, new node(a));
    else if(ch == 'R') erase(root, a);
    else if(ch == 'S') printf("%d\n", ans = select(root, a));
    else printf("%d\n", ans = rnk(root, a)); 
  }
  inorder(root);
  return 0;
}

