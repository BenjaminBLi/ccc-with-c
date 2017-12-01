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


const int MAXN = 500000, mod = 1e9 + 7;

struct node{
	ll lazy, sum, mx;
	int l, r;
	bool flag;
	node(){lazy = sum = mx = 0, flag = false;}
} tree[MAXN*6];

int n, cnt;
ll orig[MAXN];
unordered_map<ll, int> compx;
ll rev[MAXN<<1];

inline void calc(int idx){
	tree[idx].sum = tree[left(idx)].sum + tree[right(idx)].sum;
	tree[idx].mx = max(tree[left(idx)].mx, tree[right(idx)].mx);
}

inline void apply(int idx, ll lazy){
	tree[idx].lazy = tree[idx].mx = lazy;
	tree[idx].flag = true;
	tree[idx].sum = lazy * (rev[tree[idx].r] - rev[tree[idx].l]);
}

inline void prop(int idx){
	if(!tree[idx].flag) return;
	apply(left(idx), tree[idx].lazy);
	apply(right(idx), tree[idx].lazy);
	tree[idx].flag = false;
}

void build(int l, int r, int idx = 1){
	tree[idx].l = l, tree[idx].r = r;
	if(l == r-1) return;
	build(l, mid(l, r), left(idx)), build(mid(l, r) , r, right(idx));
	calc(idx);
}

void upd(int l, int r, ll val, int idx = 1){
	if(tree[idx].l >= l && tree[idx].r <= r){
		apply(idx, val);
		return;
	}
	if(tree[idx].r <= l || tree[idx].l >= r) return;
	prop(idx);
	upd(l, r, val, left(idx)), upd(l, r, val, right(idx));
	calc(idx);
}

ll qrySum(int l, int r, int idx = 1){
	if(tree[idx].l >= l && tree[idx].r <= r)
		return tree[idx].sum;
	if(tree[idx].r <= l || tree[idx].l >= r) return 0;
	prop(idx);
	return qrySum(l, r, left(idx)) + qrySum(l, r, right(idx)); 
}

ll qryMx(int l, int r, int idx = 1){
	if(tree[idx].l >= l && tree[idx].r <= r)
		return tree[idx].mx;
	if(tree[idx].r <= l || tree[idx].l >= r) return 0;
	prop(idx);
	return max(qryMx(l, r, left(idx)), qryMx(l, r, right(idx)));
}


struct book{
	int id;
	ll s, l, w;
	book(){s = l = w = 0;}
}books[MAXN];

int main(){
	//I wonder if I mle....
	scanf("%d", &n);
	fori(i, 0, n){
		books[i].id = i;
		scanf("%lld%lld%lld", &books[i].s, &books[i].l, &books[i].w);
		rev[left(i)] = books[i].s;
		rev[right(i)] = books[i].s + books[i].l;
	}
	sort(rev, rev + (n<<1));
	int cnt = unique(rev, rev + (n<<1)) - rev;
	fori(i, 0, cnt) compx[rev[i]] = i;

	ll ans = 0;
	build(0, cnt);

	fori(i, 0, n){
		int l = compx[books[i].s], r = compx[books[i].s+books[i].l];
		ll currH = qryMx(l, r);
		ll covered = qrySum(l, r);
		ans += 1LL * (books[i].l) * currH - covered;
		upd(l, r, currH + books[i].w);
	}

	cout << ans%mod << endl;
	

	return 0;
}
