#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i<N;i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

typedef vector<int> vi;


//int N;
ll D[500010], N, tot;
vi adj[500010];
bool visited[500010];

void dfs(int st, int curr){
	//printf("%d %d %d\n", st, en, curr);
	if(curr != st) tot++;
	visited[curr] = true;
	for(int v : adj[curr]){
		if(!visited[v]){
			//visited[v] = true;
			dfs(st, v);
			//visited[v] = false;
		}
	}
	visited[curr] = false;
}

int main(){
	scanf("%lld", &N);
	fori(i, N) scanf("%lld", D+i+1);
	int u, v;
	fori(i, N-1){
		scanf("%d %d", &u, &v);
		if(D[u] <= D[v]) adj[u].push_back(v);
		if(D[v] <= D[u]) adj[v].push_back(u);
	}

	tot = 0;
	dfs(1, 1);
	cout << tot << endl;
	return 0;
}