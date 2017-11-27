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

const int MAXN = 100001;

struct node{
	int l, r;
	ll sum;
	ll mxl, mxr, mxc;
	node(){sum = mxl = mxr = mxc = 0;}
}tree[MAXN<<2];

int n, q;
ll orig[MAXN];

inline node calc(int idx, node &a, node &b){
	node ret = tree[idx];
	ret.sum = a.sum + b.sum;
	ret.mxc = max(ret.sum, max(a.mxc, b.mxc));
	ret.mxl = max(a.mxl, a.sum + b.mxl);
	ret.mxr = max(a.mxr + b.sum, b.mxr);
	ret.mxc = max(max(ret.mxc, a.mxr + b.mxl), max(ret.mxl, ret.mxr));
	return ret;
}

inline void apply(int idx, ll val){
	tree[idx].sum = tree[idx].mxl = tree[idx].mxr = tree[idx].mxc = val;
}

void build(int l, int r, int idx = 1){
	tree[idx].l = l, tree[idx].r = r;
	if(l == r){
		apply(idx, orig[l]);
		return;
	}
	build(l, mid(l, r), left(idx)), build(mid(l, r)+1, r, right(idx));
	tree[idx] = calc(idx, tree[left(idx)], tree[right(idx)]);
}

void upd(int p, ll val, int idx = 1){
	if(tree[idx].l > p || tree[idx].r < p) return;
	if(tree[idx].l == tree[idx].r){
		apply(idx, val);
		return;
	}
	upd(p, val, left(idx)), upd(p, val, right(idx));
	tree[idx] = calc(idx, tree[left(idx)], tree[right(idx)]);
}

node qry(int l, int r, int idx = 1){
	node ans, nl, nr;
	if(tree[idx].l > r || tree[idx].r < l) {
		ans.sum = ans.mxl = ans.mxr = ans.mxc = -10000000001LL;
		return ans;
	}
	if(l <= tree[idx].l && tree[idx].r <= r) {
		return tree[idx];
	}
	nl = qry(l, r, left(idx)), nr = qry(l, r, right(idx));
	ans = calc(idx, nl, nr);
	return ans;
}

int main(){
	scanf("%d%d", &n, &q);
	fori(i, 1, n+1) scanf("%lld", orig+i);
	build(1, n);
	
	char ch;
	int a, b;
	for(;q--;){
		scanf(" %c%d%d", &ch, &a, &b);
		if(ch == 'S') upd(a, b);
		else printf("%lld\n", qry(a, b).mxc);
	}
	return 0;
}

