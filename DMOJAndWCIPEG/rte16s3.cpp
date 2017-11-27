#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, unsigned int> ii;
typedef long long ll;
typedef vector<ii> vii;

int n, st;

unsigned int dist[6000][6000];

vii adj[6000];//, tree[6010];
bool vis[6000];

unsigned int dfs(int u, unsigned int d){
	vis[u] = true;
	for(ii e : adj[u]){
		if(!vis[e.f]) {
			dist[st][e.f] = d + e.s;
			dfs(e.f, e.s + d);
		}
	}
	return d;
}

int main(){
	scanf("%d", &n);
	fori(i, 1, n){
		int u, v;
		unsigned int w;
		scanf("%d%d%u", &u, &v, &w);
		adj[u].pb(ii(v, w));
		adj[v].pb(ii(u, w));
	}

	fori(i, 0, n){
		fori(j, 0, n) vis[j] = false;
		dist[i][i] = 0;
		st = i;
		dfs(i, 0);
	}
	int q;
	scanf("%d", &q);
	for(;q--;){
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%u\n", dist[u][v]);
	}
	return 0;
}
