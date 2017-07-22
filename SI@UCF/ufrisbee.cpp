#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
int n, m, col[200010], cnt[200010];
bool ok;
ii curr;
vi adj[200010];
unordered_map<int, int> pairs, memo[200010];

class ufrisbee {
public:


	int opt(int a, int b){
		if(abs(a) > abs(b)) return b;
		return a;
	}

	int dp(int idx, int sum){
		if(memo[idx].count(sum)) return memo[idx][sum];
		if(idx == (int) pairs.size()){
			return sum;
		}
		int best = 0x3f3f3f;
		best = opt(best, dp(idx+1, sum + pairs[idx]));
		best = opt(best, dp(idx+1, abs(sum - pairs[idx])));
		memo[idx][sum] = best;
		return best;
	}

	void dfs(int u){
		if(col[u]) curr.f++;
		else curr.s++;
		for(int v : adj[u]){
			if(col[v] == col[u]){
				ok = false;
				return;
			}else if(col[v] == -1){
				col[v] = 1-col[u];
				dfs(v);
			}
		}
	}

	void solve(istream& in, ostream& out) {
		ok = true;
        in >> n >> m;
		fori(i, 0, m){
            int u, v;
            in >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		memset(col, -1, sizeof(col));
		fori(i, 1, n+1){
			if(col[i] == -1){
				if(i != 1){
                    out << "Impossible" << "\n";
					return;
				}
				curr == ii(0, 0);
                col[i] = 0;
				dfs(i);
				pairs[abs(curr.f-curr.s)]++;
			}
		}
        int bDiff = dp(0, 0);
		int a = n/2-bDiff/2;
		int b = n/2+bDiff/2;
		if(n&1) b++;
		out << a << " " << b << endl;
	}
};