#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define pb push_back
#define f first
#define s second
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r) >> 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ull, int> ui;
typedef long long ll;


const int MAXN = 200000;

struct node{
	ll lazy, sum, mx;
	int l, r;
	bool flag;
	node(){lazy = sum = mx = 0, flag = false;}
} tree[MAXN<<2];

int m, q, n, cnt;
ll orig[MAXN];

inline void calc(int idx){
	tree[idx].sum = tree[left(idx)].sum + tree[right(idx)].sum;
}

inline void apply(int idx, ll lazy){
	tree[idx].lazy += lazy;
	tree[idx].flag = true;
	tree[idx].sum += lazy * (tree[idx].r - tree[idx].l+1);
}

inline void prop(int idx){
	if(!tree[idx].flag) return;
	apply(left(idx), tree[idx].lazy);
	apply(right(idx), tree[idx].lazy);
	tree[idx].flag = false;
	tree[idx].lazy = 0;
}

void build(int l, int r, int idx = 1){
	tree[idx].l = l, tree[idx].r = r;
	if(l == r) {
		tree[idx].sum = orig[l];
		return;
	}
	build(l, mid(l, r), left(idx)), build(mid(l, r) + 1, r, right(idx));
	calc(idx);
}

void upd(int l, int r, ll val, int idx = 1){
	if(tree[idx].l >= l && tree[idx].r <= r){
		apply(idx, val);
		return;
	}
	if(tree[idx].r < l || tree[idx].l > r) return;
	prop(idx);
	upd(l, r, val, left(idx)), upd(l, r, val, right(idx));
	calc(idx);
}

ll qrySum(int l, int r, int idx = 1){
	if(tree[idx].l >= l && tree[idx].r <= r)
		return tree[idx].sum;
	if(tree[idx].r < l || tree[idx].l > r) return 0;
	prop(idx);
	return qrySum(l, r, left(idx)) + qrySum(l, r, right(idx)); 
}

int main(){
	scanf("%d%d%d", &m, &n, &q);
	fori(i, 0, n) scanf("%lld", orig+i);
	build(0, n-1);
	int id, l, r;
	ll x;

	for(;q--;){
		scanf("%d%d%d", &id, &l, &r);
		l--, r--;
		if(id == 1){
			scanf("%lld", &x);
			upd(l, r, x);
		}else{
			printf("%lld\n", qrySum(l, r) % m);
		}
	}

	return 0;}
