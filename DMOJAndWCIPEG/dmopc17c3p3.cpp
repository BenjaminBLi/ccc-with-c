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

const int MAXN = 1<<20;

int n, s[20], p1 = -1, p2 = -1;
ll memo[MAXN];
bool vis[MAXN];

void gen(int mask, ll sum){
	if(memo[mask] != -1) return;
	memo[mask] = sum;
	fori(i, 0, n){
		if(mask & (1<<i)) continue;
		gen(mask | (1<<i), sum + s[i]);
	}
}

inline ll ast(ll a){
	if(a < 0) return -a;
	return a;
}

void solve(int mask){
	//check all bitmasks without current mask
	if(p1 != p2 && memo[p1] == memo[p2]) return;
	if(vis[mask] || __builtin_popcount(mask) > (n+1)/2) return;
	vis[mask] = true;
    for (int cmask = ((1<<n)-1)&~mask; cmask; cmask = (cmask-1)&(((1<<n)-1)^mask)) {
        if(p1 == -1 || ast(memo[p1]-memo[p2]) > ast(memo[mask] - memo[cmask])){
        	p1 = mask;
        	p2 = cmask;
        }
    }
	fori(i, 0, n){
		if(mask & (1<<i)) continue;
		solve(mask | (1<<i));
	}
}

int main(){
	scanf("%d", &n);
	fori(i, 0, n) scanf("%d", s+i);
	fori(i, 0, (1<<n)) memo[i] = -1;
	gen(0, 0);
	fori(i, 0, n) solve(1<<i);
	fori(i, 0, n) if(p1 & (1<<i)) printf("%d ", i+1); printf("\n");
	fori(i, 0, n) if(p2 & (1<<i)) printf("%d ", i+1); printf("\n");
	return 0;
}
