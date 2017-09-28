#include <bits/stdc++.h>
#define fori(i, n) for(int i =0; i< n; i++)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
int N, M, dist[100010], dist2[100010];

vii adj[100010];

void sssp(){
	priority_queue<ii, vii, greater<ii>> pq;
	memset(dist, 0x3f3f3f, sizeof(dist));
	dist[0] = 0;
	pq.push(ii(0, 0));
	while(!pq.empty()){
		int u = pq.top().s; pq.pop();
		for(ii v : adj[u]){
			if(dist[u] + v.s <= dist[v.f]){
				dist[v.f] = dist[u]+v.s;
				pq.push(ii(dist[v.f], v.f));
			}
		}
	}
	//fori(i, N) printf("%d, ", dist[i]); cout << endl;
}
void sssp2(int st){
	priority_queue<ii, vii, greater<ii>> pq;
	memset(dist2, 0x3f3f3f, sizeof(dist2));
	dist2[st] = 0;
	pq.push(ii(0, st));
	while(!pq.empty()){
		int u = pq.top().s; pq.pop();
		for(ii v : adj[u]){
			if(dist2[u] + v.s <= dist2[v.f]){
				dist2[v.f] = dist2[u]+v.s;
				pq.push(ii(dist2[v.f], v.f));
			}
		}
	}
	//fori(i, N) printf("%d, ", dist2[i]); cout << endl;
}
void solve(){
	sssp();
	sssp2(N-1);
	int best = 0;
	for(int i = 0; i < N-1; i++){
		best = max(best, dist[i] + dist2[i]);

	}
	printf("%d\n", best);
}

int main(){
	scanf("%d %d", &N, &M);
	int u, v, w;
	for(int i =0; i < M; i++){
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(ii(v, w));
		adj[v].push_back(ii(u, w));
	}
	solve();

	return 0;
}