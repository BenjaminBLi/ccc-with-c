#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int T, N, M, G;
long long dist[3010];

vii adj[3010];
bool is[2010];

int main(){	
	scanf("%d %d %d %d", &T, &N, &M, &G);
	queue<int> q;
	int tmp;
	for(int i =0;i < G; i++){
		scanf("%d", &tmp);
		is[tmp] = true;
	}
	for(int i =0;i < M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(ii(v, w));
	}
	priority_queue<ii, vii, greater<ii>> pq;
	fill(dist, dist+N+1, 0x3f3f3f3f3f3fLL);
	pq.push(ii(0, 0));
	dist[0] = 0;
	while(!pq.empty()){
		int u = pq.top().s; pq.pop();
		for(ii v : adj[u]){
			if(dist[v.f] > dist[u]+v.s){
				dist[v.f] = dist[u]+v.s;
				pq.push(ii(dist[v.f], v.f));
			}
		}
	}
	int cnt = 0;
	for(int i =0;i <= N; i++){
		if(is[i] && dist[i] <= T){
			cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}