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
typedef double lf;

const int MAXN = 200010;

struct node{
	int l, r;
	ll lazy, mx;
	bool flag;
	node(){lazy = mx = 0; flag = false;}
}tree[MAXN*3];

inline void apply(int idx, ll lazy){
	tree[idx].lazy += lazy;
	tree[idx].flag = true;
	tree[idx].mx += lazy;
}

inline void calc(int idx){
	tree[idx].mx = max(tree[left(idx)].mx, tree[right(idx)].mx);
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
	if(l == r) return;
	build(l, mid(l, r), left(idx)), build(mid(l, r) + 1, r, right(idx));
	calc(idx);
}

void upd(int l, int r, ll val, int idx = 1){
	if(l <= tree[idx].l && tree[idx].r <= r){
		apply(idx, val);
		return;
	}
	if(tree[idx].r < l || tree[idx].l > r) return;
	prop(idx);
	upd(l, r, val, left(idx)), upd(l, r, val, right(idx));
	calc(idx);
}

ll qry(int l, int r, int idx = 1){
	if(tree[idx].r < l || tree[idx].l > r) return 0;
	if(l <= tree[idx].l && tree[idx].r <= r) return tree[idx].mx;
	prop(idx);
	return max(qry(l, r, left(idx)), qry(l, r, right(idx)));
}

int n, k, q;

int main(){
	scanf("%d%d%d", &n, &k, &q);
	build(0, n-1);
	int id, a, b;
	for(;q--;){
		scanf("%d%d%d", &id, &a, &b);
		if(id == 0){
			upd(max(0, a-k+1), min(n-1, a), b);
		}else{
			printf("%lld\n", qry(max(0, a), min(n-1, b)));
		}
	}
	return 0;
}

