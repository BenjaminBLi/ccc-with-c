#include <bits/stdc++.h>
using namespace std;

char u, v;

bool visited[26], adj[26][26], poss;

void dfs(int curr){
	//cout << (char) ('A'+curr) << endl;
	if(curr == 1) {
		//cout << "YES" << endl;
		poss = true;
		return;
	}
	visited[curr] = true;
	for(int i = 0; i < 26; i++){
		if(!visited[i] && adj[curr][i]){
			visited[i] = true;
			dfs(i);
			visited[i] = false;
		}
	}
}

int main(){
	//u = getchar(); v = getchar();
	while(scanf(" %c %c", &u, &v) && !(u == '*' && v == '*')){
		//cout << u << ", " << v << endl;
		adj[u-'A'][v-'A'] = true;
		adj[v-'A'][u-'A'] = true;
		//getchar();
		//u = getchar(); v = getchar();
	}
	//cout << "DONE" << endl;
	int cnt = 0;
	for(int i = 0; i < 26; i++){
		for(int j= i+1; j < 26; j++){
			if(adj[i][j]){
				adj[i][j] = false; adj[j][i] = false;
				memset(visited, false, sizeof(visited));
				poss = false;

				dfs(0);
				adj[i][j] = true; adj[j][i] = true;
				if(!poss){
					cnt++;
					printf("%c%c\n", 'A'+i, 'A'+j);
				} 
			}
		}
	}
	printf("There are %d disconnecting roads.\n", cnt);
	return 0;
}