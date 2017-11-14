#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i << 1)
#define right(i) (i << 1|1)
#define mid(l, r) ((l + r)>>1)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, unsigned int> ii;
typedef long long ll;

struct node{
	ll sum, lazy;
	node(){sum = -1; lazy = 0;}
};

const int MAXN = 200010;
int n, q, m;
ll orig[MAXN];
node tree[MAXN<<2];

inline ll getSum(int idx, int l, int r){return tree[idx].sum + 1LL*(r-l+1)*tree[idx].lazy;}


void pushDown(int idx, int l, int r){
	tree[idx].sum += 1LL*(r-l+1)*tree[idx].lazy;
	if(l != r){
		tree[left(idx)].lazy += tree[idx].lazy;
		tree[right(idx)].lazy += tree[idx].lazy;
	}
	tree[idx].lazy = 0;
}

void pullUp(int idx, int l, int r){
	tree[idx].sum = getSum(left(idx), l, mid(l, r)) + getSum(right(idx), mid(l, r)+1, r);
}
void build(int idx, int l, int r){
	if(l == r){
		tree[idx].sum = orig[l];
		return;
	}
	build(left(idx), l, mid(l, r)), build(right(idx), mid(l, r)+1, r);
	tree[idx].sum = tree[left(idx)].sum + tree[right(idx)].sum;
}

void build(){
	build(1, 0, n-1);
}


void upd(int idx, int l, int r, int i, int j, ll val){
	if(l > r || i > r || j < l) return;
	if(l >= i && r <= j){
		tree[idx].lazy += val;
		return;
	}
	pushDown(idx, l, r);
	upd(left(idx), l, mid(l, r), i, j, val), upd(right(idx), mid(l, r)+1, r, i, j, val);
	pullUp(idx, l, r);
}

void upd(int l, int r, ll val){
	upd(1, 0, n-1, l, r, val);
}

ll qry(int idx, int l, int r, int i, int j){
	if(l > r || i > r || j < l) return 0;
	if(l >= i && r <= j) return getSum(idx, l, r);
	pushDown(idx, l, r);
	ll ret = qry(left(idx), l, mid(l, r), i, j)%m + qry(right(idx), mid(l, r)+1, r, i, j)%m;
	ret %= m;
	pullUp(idx, l, r);
	return ret%m;
}

ll qry(int l, int r){
	return qry(1, 0, n-1, l, r);
}

int main(){
	scanf("%d%d%d", &m, &n, &q);
	fori(i, 0, n) scanf("%lld", orig+i);
	build();
	int id, l, r;
	ll x;
	while(q--){
		scanf("%d%d%d", &id, &l,  &r);
		l--, r--;
		if(id == 1){
			scanf("%lld", &x);
			upd(l, r, x);
		}else{
			printf("%lld\n", qry(l, r)%m);
		}
	}
	return 0;
}