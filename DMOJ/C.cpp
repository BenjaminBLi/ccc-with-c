#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int N, u, v, cnt[(int)2e5+1], col[(int)2e5+1];
bool valid, visited[(int) 2e5+1];
vi tree[(int)2e5+1];
vii edges;

void dfs(int curr){
	printf("%d: %d, ", curr+1, valid);
	visited[curr] = true;
	for(int n : tree[curr]){
		if(!visited[n]){
			valid &= col[curr] == col[n];
			dfs(n);
		}
	}
}

bool check(int start){
	memset(visited, false, sizeof(visited));
	valid = true;
	cout << "CHECKING: " << start << endl;
	dfs(start);
	cout << endl;
	return valid;
}



int main(){
	scanf("%d", &N);
	for(int i =0 ; i < N-1; i++){
		scanf("%d %d", &u, &v);
		u--; v--;
		tree[u].push_back(v); tree[v].push_back(u);
	}
	for(int u =0; u < N; u++)scanf("%d", &col[u]);
	for(int u = 0; u < N; u++) for(int v : tree[u]){
		if(col[u] != col[v]) edges.push_back(ii(u, v));
	}

	if(edges.empty()) cout << "YES" << endl << (1) << endl;
	else{
		ii test = edges[0];
		bool poss = true;
		for(int n : tree[test.first]){
			poss &= check(n);
			cout << (n+1) << " " << poss << endl;
		}
		cout << (test.first+1) << " " << poss << endl;
		bool poss2 = true;
		for(int n : tree[test.second]){
			poss2 &= check(n);
		}
		if(poss) cout << "YES" << endl << (test.first+1) <<  endl;
		if(poss2) cout << "YES" << endl << (test.second+1) << endl;
		else cout << "NO" << endl;
	}
	return 0;
}