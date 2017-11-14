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


const int MAXN = 100010;

int ft[MAXN], n, q, prevs[MAXN];

void upd(int idx, int val){
	for(; idx <= MAXN; idx += idx & (-idx)) ft[idx] += val;
}

int qry(int idx){
	int ret = 0;
	for(;idx; idx -= idx & (-idx)) ret += ft[idx];
	return ret;
}

int qry(int l, int r){
	return qry(r) - qry(l-1);
}

int main(){
	scanf("%d", &n);
	for(;n--;){
		int l, r;
		scanf("%d%d", &l, &r);
		int rans = qry(r);
		int lans = qry(l);
		int ans = rans + lans;
		ans -= prevs[l] + prevs[r];
		prevs[l] = ans;
		prevs[r] = ans;
		printf("%d\n", ans);
		if(l < r){
			upd(l+1, 1);
			upd(r, -1);
		}
	}
	
	return 0;
}
