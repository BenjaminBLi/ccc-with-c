#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


long long N, M, dist[200010];
bool visited[200010];
vii adj[200010];

int main(){
	scanf("%lld %lld", &N, &M);
	ll u, v, w; 
	for(int i =0; i < N; i++){
		scanf("%lld %lld %lld", &u, &v, &w);
		adj[u].push_back(ii(w, v));
		adj[v].push_back(ii( w, u));
	}
	//queue<int> q;
	memset(dist, -1, sizeof(dist));
	priority_queue<ii> pq;
	pq.push(ii(100000000000000, 1));
	//visited[1] = true;
	ll cdist, curr;
	while(!pq.empty()){
		cdist = pq.top().first;
		curr = pq.top().second;
		pq.pop();
		if(visited[curr]) continue;
		//cout << curr << endl;
		dist[curr] =  cdist;
		visited[curr] = true;
		for(ii edge : adj[curr]){
			//if(!visited)
			pq.push(ii(min(edge.first, cdist), edge.second));
		}
	}
	printf("0\n");
	for(int i = 2; i <= N; i++) printf("%lld\n", dist[i]);
	return 0;
}