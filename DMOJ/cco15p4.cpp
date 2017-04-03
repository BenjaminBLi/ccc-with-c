#include <bits/stdc++.h>
#define sz 4000010
using namespace std;
typedef vector<int> vi;

int N, M, dc[4] = {1, -1, 0, 0}, dr[4] = {0, 0, 1, -1}, inDeg[sz];
set<int> used;
char grid[4000010];
vi adj[4000010];
bool visited[4000010];

int main(){
	scanf("%d %d", &N, &M);
	char ch;
	queue<int> q;
	for(short i =0;i < N; i++){
		for(short j =0;j < M; j++){
			scanf(" %c", &ch);
			if(ch == 'E') grid[i*N+j] = 0;
			else if(ch == 'W') grid[i*N+j] = 1;
			else if (ch == 'S') grid[i*N+j] = 2;
			else if(ch == 'N') grid[i*N+j] = 3;
			else grid[i*N+j] = -1;
			if(grid[i*N+j] != -1) {
				used.insert(N*i+j);
			}
		}
	}
	int curr;
	int r, c, idx, dirX, dirY;
	for(int u : used){
		curr = u;
		idx = grid[curr];
		dirX = dr[idx], dirY = dc[idx];
		//cout << "START: " << curr.first << ", " << curr.second << endl;
		r = curr/N+dirX, c = curr%N+dirY;
		for(; r >= 0 && r < N && c >= 0 && c < M; r+=dirX, c+= dirY){
			//cout << r << ", " << c << endl;
			if(grid[r*N+c] != -1){
				adj[r*N+c].push_back(curr);
				inDeg[curr]++;
			}
		}
		//cout << endl;
	}
	queue<int> bfs;
	for(int i : used){
		//printf("(%d %d), {", i/N, i%N);for(int v : adj[i]) printf("(%d, %d), ", v/N, v%N); printf("} inDeg: %d\n", inDeg[i]);
		if(inDeg[i] == 0){
			bfs.push(i);
		}
	}

	while(!bfs.empty()){
		int u = bfs.front();bfs.pop();
		printf("(%d,%d)\n", u/N, u%N);
		visited[u] = true;
		for(int v : adj[u]){
			if(!visited[v] && --inDeg[v] == 0){
				bfs.push(v);
			}
		}
	}

	return 0;
}