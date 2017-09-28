#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int>  vi;
typedef vector<ii> vii;
struct edge{
	int v, t, h;
	edge(int vv, int tt, int hh){
		v = vv; t = tt; h = hh;
	}
};

vector<edge> adj[2010];
int K, N, M, a, b, t, h, dist[2010][201];
bool ys[2010];

int dijkstras(int st, int en){
	priority_queue<ii, vii, greater<ii>> pq;
	memset(dist, 0x3f3f3f, sizeof(dist));
	pq.push(ii(0, st));
	ys[st] = true;
	dist[st][0] = 0;
	//cout << en << endl;
	while(!pq.empty()){;
		int u = pq.top().second; pq.pop();
		//cout << u << endl;
		ys[u] = false;
		for(edge v : adj[u]){
			//int o = dist[u][i] + v.t;
			cout << v.v << endl;
			for(int i = 0; i+v.h < K; i++){
				int o = dist[u][i] + v.t;
				//cout << o << endl;
				if(o < dist[v.v][i+v.h]){
					//cout << "YES" << endl;
					dist[v.v][i+v.h] = o;
					if(!ys[v.v]){
						pq.push(ii(o, v.v));
						ys[v.v] = true;
					}
				}
			}
		}
	}
	int best = 0x3f3f3f;
	for(int i =0; i < K; i++) best = min(best, dist[en][i]);
	if(best == 0x3f3f3f) return -1;
	return best;
}

int main(){
	scanf("%d %d %d", &K, &N, &M);
	//edge tmp;
	for(int i =0 ; i < M; i++){
		scanf("%d %d %d %d", &a, &b, &t, &h);
		adj[a].push_back(edge(b, t, h));
		adj[b].push_back(edge(a, t, h));
	}
	//scanf("%d %d", &a, &b);
	cout << dijkstras(0, N-1) << endl;
	return 0;
}