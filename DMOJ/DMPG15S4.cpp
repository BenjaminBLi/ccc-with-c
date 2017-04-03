#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int B, Q, x, y, r;

struct bec{
	int x, y, r;
};

vi adj[510];
bec becs[510];
bool v[510], poss;

void dfs(int c){
	//cout << (c+1) << endl;
	if(c == y) {
		poss |= true;
		return;
	}
	v[c] = true;
	for(int n : adj[c]){
		if(!v[n]) dfs(n);
	}
	//return false;
}

int main(){
	scanf("%d %d", &B, &Q);
	for(int i =0; i < B; i++){
		scanf("%d %d %d", &becs[i].x, &becs[i].y, &becs[i].r);
	}
	for(int i =0 ; i < B; i++){
		for(int j = 0; j < B; j++){
			if(j == i) continue;
			if((becs[j].x-becs[i].x)*(becs[j].x-becs[i].x)+(becs[j].y-becs[i].y)*(becs[j].y-becs[i].y) <= becs[i].r*becs[i].r){
				//cout << (i+1) << ", " << (j+1) << endl;
				adj[i].push_back(j);
			}
		}
	}

	for(int i =0 ; i < Q; i++){
		scanf("%d %d", &x, &y);
		memset(v, false, sizeof(v)); poss = false;
		x--; y--;
		//cout << (y+1) << endl;
		dfs(x);
		if(poss) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}