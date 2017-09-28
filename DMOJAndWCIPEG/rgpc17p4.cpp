#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

ll n, m, x, y, z, dis, poi, st, cnt, dist[1005], points[1005]; vector <pair <ll, ll> > graph[1005]; queue <ll> pq; 
bool ch, visit[1005]; 

void dfs (int u, int k){
	if (u == st && k != 0){
		ch = true; 
	}
	if (visit[u]) return; 
	visit[u] = true; 
	for (int i = 0; i < graph[u].size(); i++){
		dfs(graph[u][i].second, k+1); 
	}
}

bool check(){
	for (int i = 1; i <= n; i++){
		memset (visit, false, sizeof visit); 
		st = i; 
		dfs(i, 0); 
		if (ch) break; 
	}
	return ch; 
}

int main() {
	scan(n); scan(m);
	for (int i = 0; i < m; i++){
		scan(x); scan(y); scan(z);
		graph[x].pb(mp(z, y)); 
	}
	if (check()){
		printf ("-1\n");
		return 0; 
	}
	pq.push(1); 
	points[1] = 1; 
	while (!pq.empty()){
		x = pq.front();
		pq.pop(); 
		cnt++; 
		for (int i = 0; i < graph[x].size(); i++){
			if (dist[graph[x][i].second] < dist[x] + graph[x][i].first){
				pq.push(graph[x][i].second);
				points[graph[x][i].second] = points[x]+1; 
				dist[graph[x][i].second] = dist[x] + graph[x][i].first;
			}
			else if (dist[graph[x][i].second] == dist[x] + graph[x][i].first && points[graph[x][i].second] < points[x]+1){
				pq.push(graph[x][i].second);
				points[graph[x][i].second] = points[x]+1; 
				dist[graph[x][i].second] = dist[x] + graph[x][i].first;
			}
		}
	}
	if (dist[x] == 0) printf ("-1\n"); 
	else printf ("%lld %lld", dist[n], points[n]); 
	return 0;
}