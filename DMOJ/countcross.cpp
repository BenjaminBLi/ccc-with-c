#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, K, R;

struct field{
	bool wall[4];
	int cnt;
	bool blocked;
};

field fields[101][101];
bool visited[101][101], seen[101][101];
ii cows[100];
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
//{N, E, S, W}
bool check(int r, int c){
	if(r == N && c == N && fields[r][c].cnt >= 2) return true;
	else if (c < N && r == N && fields[r][c].cnt >= 3) return true;
	else if (c == N && r < N && fields[r][c].cnt >= 3) return true;
	else if(c < N && r < N && fields[r][c].cnt >= 4) return true;
	return false;
}
void bfs(int r, int c){
	queue<ii> q;
	q.push(ii(r, c));
	ii curr;
	//int r, c;
	bool init = visited[r][c];
	memset(visited, false, sizeof(visited));
	while(!q.empty()){
		curr = q.front(); q.pop();
		r = curr.first; c = curr.second;
		visited[r][c] = true;
		seen[r][c] = true;
		for(int i =0; i < 4; i++){
			if(fields[r][c].wall[i] || r + dx[i] <= 0 || r+dx[i] > N || c+dy[i] > N || c+dy[i] >= 0) continue;
			q.push(ii(r+dx[i], c+dy[i]));
		}
	}
	seen[r][c] = init;
}
int main(){
	//freopen("countcross.in", "r", stdin);
	//freopen("countcross.out", "w", stdout);
	scanf("%d %d %d", &N, &K, &R);
	int r, c, r1, c1;
	for(int i =0; i < R; i++){
		scanf("%d %d %d %d", &r, &c, &r1, &c1);
		if(r1 == r){
			if(c > c1){
				fields[r][c].wall[0] = true;
				fields[r1][c1].wall[2] = true;
			}
			else{
				fields[r][c].wall[2] = true;
				fields[r1][c1].wall[0] = true;
			}
		}else{
			if(r > r1){
				fields[r][c].wall[3] = true;
				fields[r1][c1].wall[1] = true;
			}
			else{
				fields[r][c].wall[1] = true;
				fields[r1][c1].wall[3] = true;
			}
		}
	}
	int a, b;
	ii valid;
	for(int i =0; i < K; i++){
		scanf("%d %d", &a, &b);
		//isCow[a][b] = true;
		cows[i] = ii(a, b);
		fields[a][b].cnt = 0;
		for(int i =0; i < 4; i++)if(fields[a][b].wall[i])fields[a][b].cnt++;
		fields[a][b].blocked = check(a, b);
		if(!fields[a][b].blocked) bfs(a, b);
	}
	//bfs(valid.first, valid.second);
	int cnt = 0;
	
	for(int i =0; i < K; i++){
		for(int j = i+1; j < K; j++){
			if(fields[cows[i].first][cows[i].second].blocked || fields[cows[j].first][cows[j].second].blocked)cnt++;
		}
	}
	
	//cout << no << endl;
	//no = no*(no-1)/2;
	cout << cnt << endl;
	return 0;
}