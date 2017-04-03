#include <bits/stdc++.h>
#define thr(x) x.second.second
#define sec(x) x.second.first
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;

long long L, A, B, W, dist[10010], stretch[10010], maxT[10010];
bool is[10010], inc[10010];
int N, M, X, Y, S;
vii adj[10010];

bool dijkstras(int maxT, int st, int en){
	priority_queue<ii, vii, greater<ii>> pq;
	memset(dist, 0x3f3f3f, sizeof(dist)); memset(stretch, 0x3f3f3f, sizeof(dist));
	memset(inc, false, sizeof(inc));
	pq.push(ii(0, st));
	inc[st] = true;
	stretch[st] = 0;
	dist[st] = 0;
	//cout << dist[1] << endl;
	while(!pq.empty()){
		int u = pq.top().second; pq.pop();
		inc[u] = false;
		//cout << u << endl;
		for(ii v : adj[u]){
			int str = -1;
			if(is[u]) str = v.second;
			else str = stretch[u]+v.second;
			if(!inc[v.first] && dist[v.first] > dist[u] + v.second  && dist[u] + v.second <= L 
				&& str <= maxT && str < stretch[v.first]){
				//cout << "YES" << endl;
				dist[v.first] = dist[u] + v.second;
				stretch[v.first] = str;
				inc[v.first] = true;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	//ll bst = 0x3f3f3f;
	//cout << (ll)(0x3f3f3f) << ", " << dist[en] << endl;
	return dist[en] != 4557430888798830399LL;
}

int bfind(){
	long long hi = (long long) 1e9+1, lo = 0, mid;
	for(int i =0; i < 60; i++){
		mid = lo+(hi+lo)/2LL;
		printf("%lld %lld %lld\n", hi, mid, lo);
		if(dijkstras(mid, X, Y)) hi = mid-1;
		else lo = mid+1;
	}
	printf("%lld %lld %lld\n", hi, mid, lo);
	if(hi == 0 || lo == (ll) 1e9) return -1;
	return mid;
}

int main(){
	scanf("%d %d %d %d %lld", &N, &M, &X, &Y, &L);
	for(int i =0; i < N; i++){
		scanf("%d %d %lld", &A, &B, &W);
		adj[A].push_back(ii(B, W));
	}
	scanf("%d", &S);
	for(int i =0; i < S; i++){
		scanf("%d", &A);
		is[A-1] = true;
	}
	//cout << dijkstras(4, X, Y) << endl;
	//cout << bfind() << endl;
	return 0;
}