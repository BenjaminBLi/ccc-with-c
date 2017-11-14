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

struct edge{
	int u, v, w;
	edge *next;
};

const int inf = 0x3f3f3f3f, MAXN = 30010, MAXM = 30010;

int n, m, dist[MAXN], ecnt = 0;
set<int> doges[MAXN];
edge es[MAXN*10], *adj[MAXN]; 
bool vis[MAXN];

inline void insE(int idx, int u){
	es[idx].next = adj[u];
	adj[u] = &es[idx];
}

void buildGraph(){
	fori(i, 0, n){
		for(int u : doges[i]){
			for(int j = 1, v = i + u; v < n; j++, v += u){
				es[ecnt] = {i, v, j};
				insE(ecnt++, i);
				if(doges[v].count(u)) break;
			}
			for(int j = 1, v = i - u; v >= 0; j++, v -= u){
				es[ecnt] = {i, v, j};
				insE(ecnt++, i);
			    if(doges[v].count(u)) break;
			}
		}
	}
}

int solve(int st, int en){
	fori(i, 0, n) dist[i] = inf;
	dist[st] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push(ii(0, st));

	while(pq.size()){
		int u = pq.top().s;
		pq.pop();
		for(edge *e = adj[u]; e; e = e->next){
			if(dist[e->v] > dist[u] + e->w){
				dist[e->v] = dist[u] + e->w;
				pq.push(ii(dist[e->v], e->v));
			}
		}
	}
	return dist[en];
}

int main(){
	scanf("%d%d", &n, &m);
	int st = -1, en = -1;
	fori(e, 0, m){
		int b, p;
		scanf("%d%d", &b, &p);
		if(e == 0) st = b;
		if(e == 1) en = b;
		doges[b].insert(p);
	}
	buildGraph();

	/*
	fori(u, 0, n){
		printf("u: %d\n", u);
		for(edge *e = adj[u]; e; e = e->next)
			printf("<%d %d>, ", e->v, e->w);
		cout << endl;
	}
	*/

	int ans = solve(st, en);
	if(ans == inf) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}
