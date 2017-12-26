#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r)>>1)
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

const int MAXN = 250010;
int n, m, a[MAXN], tmp[10];

struct node{
	int l, r, freq[10], lazy;
	bool flag;
	node(){l = r = -1;}
}tree[MAXN*3];

inline void rotate(int idx, int cnt){
	fori(i, 0, 10) tmp[i] = tree[idx].freq[i];
	fori(i, 0, 10) tree[idx].freq[(i + cnt)%10] = tmp[i];
}

inline void calc(int idx){
	fori(i, 0, 10){
		tree[idx].freq[i] = tree[left(idx)].freq[i] + tree[right(idx)].freq[i];
	}
}

inline void apply(int idx, int lazy){
	tree[idx].lazy += lazy;
	tree[idx].flag = true;
	rotate(idx, lazy);
}

inline void prop(int idx){
	if(!tree[idx].flag) return;
	apply(left(idx), tree[idx].lazy);
	apply(right(idx), tree[idx].lazy);
	tree[idx].lazy = 0;
	tree[idx].flag = false;
}

void build(int l, int r, int idx = 1){
	tree[idx].l = l, tree[idx].r = r;
	if(l == r){
		tree[idx].freq[a[l]]++;
		return;
	}
	build(l, mid(l, r), left(idx)), build(mid(l, r)+1, r, right(idx));
	calc(idx);
}

int qry(int l, int r, int idx = 1){
	if(l <= tree[idx].l && tree[idx].r <= r){
		int ret = 0;
		fori(i, 0, 10) ret += i * tree[idx].freq[i];
		apply(idx, 1);
		return ret;
	}if(tree[idx].r < l || tree[idx].l > r) return 0;
	prop(idx);
	int ans = qry(l, r, left(idx)) + qry(l, r, right(idx));
	calc(idx);
	return ans;
}

int main(){
	scan(n);
	scan(m);
	fori(i, 0, n){
		a[i+1] = getchar()-'0';
	}
	build(1, n);
	int l, r;
	fori(i, 0, m){
		scan(l);
		scan(r);
		printf("%d\n", qry(l, r));
	}
	return 0;
}
