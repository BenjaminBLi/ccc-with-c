#include <bits/stdc++.h>
using namespace std;

/*
//Dijkstra (1 time) start from A...
A = 1, B = 3;

start from A, go to B
Dijkstra(A, B): dis1: {0, 5, 7, 8}
Dijkstra(B, A): Dis2: {7, 2, 0, inf} <-- use a reverse graph

if we have edge <u, v>:
	May be on the path from A --> B
	distance is: dis1[u] + len of <u, v> + dis2[v]
i. e edge <1, 2> with weight 5 and cost 1
lst: {(7, 1), (10, 15), (7, 15)} <-- (length, cost)

<3, 1>: dis1[3] + len of <3, 1> (80) + dis2[1] = 7 + 80 + 7 = 94

lst: {(7, 1), (10, 50), (7, 15), (94, 1000), 

<3, 4> dis1[3] + 1 + dis2[4] = inf 

lst: {(7, 1), (10, 50), (7, 15), (94, 1000), (inf, 1)}

find all the info for each edge, then sort by length.

lst: {(7, 1), (7, 15), (10, 50), (94, 1000), (inf, 1)}
Then make a prefix sum array...
lst: {(7, 1), (7, 16), (10, 66), (94, 1066), (inf, 1067)}
then just use upper bound to find the length.

dijkstra twice: st --> en, en --> st
calculate dist from edges... --> dis1[u] + len of <u, v> + dis2[v]
use upper_bound to solve the problem

*/

struct edge{
	int v, w, c;
	edge(int vv, int ww, int cc){
		v = vv, w = ww, c = cc;
	}
};


typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> llll;
typedef vector<ii> vii;
typedef vector<llll> vll;

bool comp(ii a, ii b){
	return a.first < b.first;
}
int N, M, st, en, x, y, w, c;
ll dist1[100010], dist2[100010];
llll edges[100010];
vector<edge> adj[100010], rev[100010];

int main(){
	scanf("%d %d %d %d", &N, &M, &st, &en); st--; en--;

	for(int i =0; i < M; i++){
		scanf("%d %d %d %d", &x, &y, &w, &c);
		//printf("%d %d %d %d\n", x, y, w, c);
		x--; y--;
		adj[x].push_back(edge(y, w, c));
		rev[y].push_back(edge(x, w, c));
	}

	priority_queue<llll, vll, greater<llll>> pq;
	pq.push(llll(0, st));
	memset(dist1, 0x3f3f3f, sizeof(dist1));
	dist1[st] = 0;

	while(!pq.empty()){
		int u = pq.top().second; pq.pop();
		//cout << u+1 << endl;
		for(edge v : adj[u]){
			if(dist1[v.v] > dist1[u] + v.w){
				//printf("<%d, %d>\n", u+1, 1+v.v);
				dist1[v.v] = dist1[u] + v.w;
				pq.push(llll(dist1[v.v], v.v));
			}
		}
	}
	pq.push(llll(0, en));
	memset(dist2, 0x3f3f3f, sizeof(dist2));
	dist2[en] = 0;
	while(!pq.empty()){
		int u = pq.top().second; pq.pop();
		for(edge v : rev[u]){
			if(dist2[v.v] > dist2[u] + v.w){
				dist2[v.v] = dist2[u] + v.w;
				pq.push(llll(dist2[v.v], v.v));
			}
		}
	}
	//for(int i =0; i < N; i++) printf("%d, ", dist1[i]); cout << endl;
	//for(int i =0; i < N; i++) printf("%d, ", dist2[i]); cout << endl;
	int cnt = 0;
	for(int i = 0; i <N; i++){
		for(edge e : adj[i]){
			edges[cnt++] = llll(dist1[i]+dist2[e.v]+e.w, e.c);
		}
	}
	sort(edges, edges+cnt, comp);
	for(int i =0; i < cnt; i++){
		if(i) edges[i] = llll(edges[i].first, edges[i].second + edges[i-1].second);
		//printf("%d %d\n", edges[i].first, edges[i].second);
	}
	int Q, D;
	scanf("%d", &Q);
	for(int q = 0; q < Q; q++){
		scanf("%d", &D);
		auto iter = upper_bound(edges, edges+cnt, llll(D, 0x3f3f3f3f3f3f));
		cout << (iter-1)->second << endl;
	}
	return 0;
}