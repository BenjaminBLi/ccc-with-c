#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i < N; i++)
using namespace std;
typedef vector<int> vi;
int N, h[500010], u, v, best, preV, d1, d2, ansV, maxH, dist[500010], dist2[500010], sz;
bool visited[500010];
vi tree[500010];

void dfs(int curr){
	//cout << curr+1 << endl;
	visited[curr] = true;
	sz++;
	for(int n : tree[curr])
		if(!visited[n]) dfs(n);

	if(sz > maxH){
		maxH = sz;
		ansV = curr;
		//printf("YES: %d, %d\n", maxH, curr+1);
	}
	sz--;
}

void bfs(int start){
	//printf("%d: %d %d\n", curr+1, sz, maxH-(sz));
	int curr;
	dist[start] = 1;
	queue<int> q;
	q.push(start);
	memset(visited, false, sizeof(visited));
	while(!q.empty()){
		curr = q.front(); q.pop();	
		visited[curr] = true;
		for(int n : tree[curr]) if(!visited[n]){
			q.push(n);
			dist[n] = max(dist[n], dist[curr]+1);
		}
	}
}

void bfs2(int start){
	int curr;
	dist2[start] = 1;
	queue<int> q;
	q.push(start);
	memset(visited, false, sizeof(visited));
	while(!q.empty()){
		curr = q.front(); q.pop();	
		visited[curr] = true;
		for(int n : tree[curr]) if(!visited[n]){
			q.push(n);
			dist2[n] = max(dist2[n], dist2[curr]+1);
		}
	}
}

int main(){
    //freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	fori(i, N-1){
		scanf("%d %d", &u, &v);
		u--; v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	sz = 0; memset(visited, false, sizeof(visited));
	dfs(u);
	preV = ansV; d1 = maxH; memset(visited, false, sizeof(visited));
	dfs(preV);
	//printf("%d, %d\n", ansV+1, preV+1);
	d2 = maxH-d1;
	//printf("MAXH: %d\n", maxH);
	bfs(ansV);
	bfs2(preV);
	fori(i, N){
		printf("%d\n", max(dist2[i], dist[i]));
	}
	return 0;
}