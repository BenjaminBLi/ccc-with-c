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
  node *l, *r;
  int val;
  node(){l = r = NULL;}
} *root = new node();

int n, a[3022];

void ins(node* &c, int val){
  if(val < c->val){
    if(c->l == NULL){
      node *p = new node();
      p->val = val;
      c -> l = p;
    }else{
      ins(c->l, val);
    }
  }else{
    if(c->r == NULL){
      node* p = new node();
      p->val = val;
      c->r = p;
    }else{
      ins(c->r, val);
    }
  }
}

void traverse(node* &c){
  if(c->r != NULL) traverse(c->r);
  if(c->l != NULL) traverse(c->l);
  printf("%d\n", c->val);
}

int main(){
  scanf("%d", &n);
  fori(i, 0, n) scanf("%d", a+i);
  root->val = a[n-1];
  rfori(i, n-2, 0)
    ins(root, a[i]);

  traverse(root);
  
  return 0;
}

