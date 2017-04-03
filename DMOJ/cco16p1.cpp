#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
int N, M, K, tCut, tTaken;
vi adj[(int)1e6+10];
bool visited[(int)1e6+10];
queue<ii> q;

void bfs(int st){
	q.push({st, -1});
	bool hasCycle = false;
	int cnt = 0;
	visited[st] = true;
	ii u;
	while(!q.empty()){
		u = q.front(); q.pop();
		//cout << u.first << endl;
		cnt++;
		for(int v : adj[u.first]){
			if(v == u.second) continue;
			if(visited[v]){
				hasCycle = true;
			}else{
				q.push({v, u.first});
				visited[v] = true;
			}
		}
	}
	//cout << "cnt: " << cnt << endl;
	if(cnt < K) return;
	tTaken += (cnt/K)*K, tCut += cnt/K;
	if(cnt%K==0) tCut--;
	if(hasCycle && cnt > K) tCut++;
	//cout << tTaken << ", " << tCut << endl;
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	int u, v;
	for(int i =0;i < M; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//make chains or cycles of size K
	//cout << "DONE" << endl;
	tCut = 0, tTaken = 0;
	for(int i =1; i <= N; i++){
		if(!visited[i]){
			bfs(i);
		}
	}
	printf("%d %d\n", tTaken, tCut);

	return 0;
}