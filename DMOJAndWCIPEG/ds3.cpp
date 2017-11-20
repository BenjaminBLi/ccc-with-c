#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
#define left(idx) (idx<<1)
#define right(idx) (idx<<1|1)
#define mid(l, r) ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

const int MAXN = 100010, inf = 0x3f3f3f3f;

struct node{
	int l, r;
	int mn, gcd, cnt;
	node(){mn = 0, cnt = gcd = 1;}
}tree[MAXN<<2];

int n, m, orig[MAXN];

inline int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

inline void calc(int idx){
	tree[idx].gcd = gcd(tree[left(idx)].gcd, tree[right(idx)].gcd);
	tree[idx].mn = min(tree[left(idx)].mn, tree[right(idx)].mn);
	tree[idx].cnt = 0;
	if(tree[idx].gcd == tree[left(idx)].gcd) tree[idx].cnt += tree[left(idx)].cnt;
	if(tree[idx].gcd == tree[right(idx)].gcd) tree[idx].cnt += tree[right(idx)].cnt;
}

inline void apply(int idx, int val){
	tree[idx].mn = tree[idx].gcd = val; 
	tree[idx].cnt = 1;
}

void build(int l, int r, int idx = 1){
	tree[idx].l = l, tree[idx].r = r;
	if(l == r) {
		apply(idx, orig[l]);
		return;
	}
	build(l, mid(l, r), left(idx)), build(mid(l, r)+1, r, right(idx));
	calc(idx);
}

void upd(int p, int val, int idx = 1){
	if(tree[idx].l > p || tree[idx].r < p) return;
	if(tree[idx].l == tree[idx].r){
		apply(idx, val);
		return;
	} 
	upd(p, val, left(idx)), upd(p, val, right(idx));
	calc(idx);
}

int qryMin(int l, int r, int idx = 1){
	if(l <= tree[idx].l && tree[idx].r <= r) return tree[idx].mn;
	if(tree[idx].l > r || l > tree[idx].r) return inf;
	return min(qryMin(l, r, left(idx)), qryMin(l, r, right(idx)));
}

int qryGcd(int l, int r, int idx = 1){
	if(l <= tree[idx].l && tree[idx].r <= r) return tree[idx].gcd;
	if(tree[idx].l > r || l > tree[idx].r) return 0;
	return gcd(qryGcd(l, r, left(idx)), qryGcd(l, r, right(idx)));
}


int qryCnt(int l, int r, int idx = 1){
	if(l <= tree[idx].l && tree[idx].r <= r) return tree[idx].cnt;
	if(tree[idx].l > r || l > tree[idx].r) return 0;
	int lGcd = qryGcd(l, r, left(idx)), rGcd = qryGcd(l, r, right(idx));
	int allGcd = gcd(lGcd, rGcd);
	int ret = 0;
	if(allGcd == lGcd) ret += qryCnt(l, r, left(idx));
	if(allGcd == rGcd) ret += qryCnt(l, r, right(idx));
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	fori(i, 1, n+1) scanf("%d", orig+i);
	build(1, n);

	char ch;
	int a, b;

	for(;m--;){
		scanf(" %c%d%d", &ch, &a, &b);
		if(ch == 'C') upd(a, b);
		else if(ch == 'M') printf("%d\n", qryMin(a, b));
		else if(ch == 'G') printf("%d\n", qryGcd(a, b));
		else printf("%d\n", qryCnt(a, b));
	}
	return 0;
}

