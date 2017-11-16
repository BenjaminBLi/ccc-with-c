#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
#define INF 0x3f3f3f3f
#define MAXN 100010
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int n, qrs, a[MAXN], m[2*MAXN], g[2*MAXN], q[2*MAXN];

int gcd(int a, int b){
	while(a && b) a > b ? a %= b : b %= a;
	return a|b;
}

void build(){
	rfori(i, n-1, 1){
		m[i] = min(m[i<<1], m[i<<1|1]);
		g[i] = gcd(g[i<<1], g[i<<1|1]);
		q[i] = (g[i] == g[i<<1] ? q[i<<1] : 0) + (g[i] == g[i<<1|1] ? q[i<<1|1] : 0); 
	}
} 

void upd(int idx, int val){
	for(idx += n, m[idx] = val, g[idx] = val; idx; idx >>= 1){
		m[idx>>1] = min(m[idx], m[idx^1]);
		g[idx>>1] = gcd(g[idx], g[idx^1]);
		q[idx>>1] = (g[idx>>1] == g[idx] ? q[idx] : 0) + (g[idx>>1] == g[idx^1] ? q[idx^1] : 0);
	}
}

int qrMin(int l, int r){
	int ret = INF;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l&1) ret = min(ret, m[l++]);
		if(r&1) ret = min(ret, m[--r]);
	}
	return ret;
}

int qrG(int l, int r){
	int ret = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l&1) ret = gcd(ret, g[l++]);
		if(r&1) ret = gcd(ret, g[--r]);
	}
	return ret;
}

int qrQ(int l, int r){
	int ql = 0, qr = 0, gr = 0, gl = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l&1){
			if(gl != gcd(gl, g[l])){
				gl = gcd(gl, g[l]);
				ql = 0;
			}if(gl == g[l]){
				ql += q[l];
			}
			l++;
		}if(r&1){
			r--;
			if(gr != gcd(gr, g[r])){
				gr = gcd(gr, g[r]);
				qr = 0;
			}if(gr == g[r]){
				qr += q[r];
			}
		}
	}
	int gfin = gcd(gr, gl);
	int ret = 0;
	if(gr == gfin) ret += qr;
	if(gl == gfin) ret += ql;
	return ret;
}

int main(){
	scanf("%d%d", &n, &qrs);
	fori(i, 0, n){
		scanf("%d", m+i+n);
		g[i+n] = m[i+n];
		q[i+n] = 1;
	}
	build();
	char ch;
	int a, b;
	fori(q, 0, qrs){
		scanf(" %c%d%d", &ch, &a, &b);
		if(ch == 'C') upd(a-1, b);
		else if(ch == 'M') printf("%d\n", qrMin(a-1, b));
		else if(ch == 'G') printf("%d\n", qrG(a-1, b));
		else printf("%d\n", qrQ(a-1, b));
	}
	return 0;
}
