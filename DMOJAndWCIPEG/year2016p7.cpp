#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l + r) >> 1)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

const int MAXN = 100010;
int n, k, a[MAXN], L[MAXN], R[MAXN];

struct node{
	int l, r;
	int id, mx;
	node(){id = -1, mx = 0;}
}tree[MAXN*3];

inline void calc(int idx){
	if(tree[left(idx)].mx > tree[right(idx)].mx || 
		(tree[left(idx)].mx == tree[right(idx)].mx && tree[left(idx)].id < tree[right(idx)].id)) tree[idx].id = tree[left(idx)].id;
	else tree[idx].id = tree[right(idx)].id; 
	tree[idx].mx = max(tree[left(idx)].mx, tree[right(idx)].mx);
}

void build(int l, int r, int idx = 1){
	tree[idx].l = l, tree[idx].r = r;
	if(l == r-1){
		tree[idx].mx = R[l];
		tree[idx].id = l;
		return;
	}
	build(l, mid(l, r), left(idx)), build(mid(l, r), r, right(idx));
	calc(idx);
}

node qry(int l, int r, int idx = 1){
	if(tree[idx].r <= l || tree[idx].l >= r) return node(); 
	if(l <= tree[idx].l && tree[idx].r <= r) return tree[idx];
	node lft = qry(l, r, left(idx)), rht = qry(l, r, right(idx));
	if(lft.mx > rht.mx || (lft.mx == rht.mx && lft.id < rht.id)) return lft;
	return rht;
}

deque<ii> maxQ, minQ;

int main(){
	scanf("%d%d", &n, &k);
	int cl = 1;
	fori(i, 1, n+1) {
		int tmp;
		scanf("%d", &tmp);
		while(maxQ.size() && maxQ.back().f > tmp) maxQ.pop_back();
		while(minQ.size() && minQ.back().f < tmp) minQ.pop_back();
		minQ.push_back(ii(tmp, i));
		maxQ.push_back(ii(tmp, i));
		while(minQ.front().f - maxQ.front().f > k){
			if(cl == maxQ.front().s) maxQ.pop_front();
			if(cl == minQ.front().s) minQ.pop_front();
			R[cl] = i - cl;
			cl++;
		}
		L[i] = i - cl + 1;
	}
	while(cl <= n) R[cl] = n + 1 - cl, cl++;
	build(1, n);

	int a, b, q;
	node ans;
	scanf("%d", &q);
	for(;q--;){
		scanf("%d%d", &a, &b);
		if(R[a] >= b-a+1) printf("%d %d\n", a, b);
		else{
			ans = qry(a, max(a, b - L[b]+1));
			if(ans.mx > L[b]) printf("%d %d\n", ans.id, ans.id + ans.mx-1);
			else if(ans.mx == L[b] && ans.id < b - L[b] + 1) printf("%d %d\n", ans.id, ans.id + ans.mx-1);
			else printf("%d %d\n", b - L[b]+1, b);
		}
	}
	return 0;
}