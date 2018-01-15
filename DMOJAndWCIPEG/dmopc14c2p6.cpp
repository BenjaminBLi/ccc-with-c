#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
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

const int MAXN = 100010;
int n, q;

struct query{
	int a, b, q;
	int id;
	query(){a = b = q = 0;}
	bool operator < (const query &o) &{
		if(q != o.q) return q > o.q;
		if(a != o.a) return a < o.a;
		return b < o.b;
	}
}queries[MAXN];

ii pts[MAXN];
ll ft[MAXN], ans[MAXN];

void upd(int i, ll val){
	for(;i <= n; i += i & (-i)) ft[i] += val; 
}

ll qry(int i){
	ll ret = 0;
	for(; i; i -= i & (-i)) ret += ft[i];
	return ret;
}

ll qry(int l, int r){
	return qry(r) - qry(l-1);
}

bool cmp(ii a, ii b){
	if(a.f != b.f) return a.f > b.f;
	return a.s < b.s;
}

int main(){
	scanf("%d", &n);
	fori(i, 0, n) {
		scanf("%d", &pts[i].f);
		pts[i].s = i+1;
	}
	sort(pts, pts+n, cmp);
	scanf("%d", &q);
	fori(i, 0, q){
		scanf("%d%d%d", &queries[i].a, &queries[i].b, &queries[i].q);
		queries[i].a++, queries[i].b++;
		queries[i].id = i;
	}

	sort(queries, queries + q);
	int pt = 0;
	fori(i, 0, q){
		//find q value
		while(pts[pt].f >= queries[i].q && pt < n){
			upd(pts[pt].s, pts[pt].f);
			pt++;
		}
		ans[queries[i].id] = qry(queries[i].a, queries[i].b);
	}
	fori(i, 0, q){
		printf("%lld\n", ans[i]);
	}

	return 0;
}
