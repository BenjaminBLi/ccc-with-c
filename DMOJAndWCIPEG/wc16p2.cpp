#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i<N;i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;

int N, M, p[200010];

long long T[200010], dist[200010];
bool visited[200010];
vii adj[200010];
ii train[200010];

int main(){
	scanf("%d %d", &N, &M);
	fori(i, N) scanf("%lld", T+i+1);

	ll u, v, w;
	fori(i, M){
		scanf("%lld %lld %lld", &u, &v, &w);
		adj[u].push_back(ii(v, w));
		adj[v].push_back(ii(u, w));
	}
	priority_queue<ii, vii, greater<ii>> pq;
	
	pq.push(ii(1, 0));
	for(int i =0;i < 200010; i++) dist[i] = 0x3f3f3f3f3f3fLL;
	while(!pq.empty()){
		u = pq.top().first, w = pq.top().second; pq.pop();
		//cout << u << endl;
		//visited[u] = true;

		for(ii v : adj[u]){
			//if(!visited[v.first]){
				if(dist[v.first] > max(w, v.second)){
					//cout << "YES" << v.first << endl;
					p[v.first] = u;
					dist[v.first] = max(w, v.second);
					pq.push(ii(v.first, max(w, v.second)));
				}
			//}
		}
		//cout << "TOP:" << pq.top().first  << ", " << pq.top().second << endl;
	}
	for(int i = 1; i <= N; i++) {
		sorted[i] = ii(dist[i], i);
	}

	int cL = 1;
	ll tot = 0;

	//if(dist[N] == 0x3f3f3f3f3f3fLL) printf("-1\n");
	cout << dist[N] << endl;

	//
	return 0;
}