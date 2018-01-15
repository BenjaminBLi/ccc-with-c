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

const int MAXN = 1000010;
int n, p, ft[MAXN];
ll arr[MAXN];
pair<ll, int> rev[MAXN];
unordered_map<int, int> id;

void upd(int i){
	for(; i <= n+10; i+= i & (-i)) ft[i]++;
}

int qry(int i){
	int ret = 0;
	for(; i; i -= i & (-i)) ret += ft[i];
	return ret;
}

int main(){
	scanf("%d", &n);
	fori(i, 0, n) {
		scanf("%lld", arr+i);
	}
	scanf("%d", &p);

	//decrease each element of the array by p
	fori(i, 0, n){
		arr[i] -= p;
		if(i) arr[i] += arr[i-1];
		rev[i] = {arr[i], i+2};
	}
	rev[n] = {0, 1};
	sort(rev, rev+n+1);

	ll cnt = 0;
	int pos = 0;
	fori(i, 0, n+1){
		while(pos < i && (rev[i].f - rev[pos].f) >= 0) upd(rev[pos++].s);
		cnt += qry(rev[i].s);
	}
	printf("%lld\n", cnt);
	return 0;
}