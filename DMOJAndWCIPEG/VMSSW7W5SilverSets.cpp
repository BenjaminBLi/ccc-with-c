#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

map<char, int> id;
map<int, char> rev;
int N, u, v, st;
char a, b, buff[50];

set<char> keys, sts[26];
vi adj[26];
bool vis[26];

void combine(int id1, int id2){
	for(char c : sts[id2])
		sts[id1].insert(c);
}

void dfs(int c){
	//cout << rev[c] << endl;
	vis[c] = true;
	//cout << "YES" << endl;
	for(int n : adj[c]){
		if(!vis[n])
			dfs(n);
		for(char ch : sts[n]) sts[st].insert(ch);
	}
	//cout << "YES" << endl;
}

int main(){
	scanf("%d", &N);
	int cnt = 0;
	for(int i =0; i < N; i++){
		getchar(); a = getchar(); scanf(" %s", buff); getchar(); b = getchar();
		keys.insert(a);
		if('A' <= b && 'Z' >= b){
			keys.insert(b);
			adj[a-'A'].push_back(b-'A');
		}
		else
			sts[a-'A'].insert(b);
	}
	for(char key : keys){
		id[key] = cnt;
		rev[cnt++] = key;
	}
	//cout << "DONE" << endl;
	for(int i = 0; i < cnt; i++){
		memset(vis, false, sizeof(vis));
		st = rev[i]-'A';
		dfs(rev[i]-'A');
	}	
	
	for(char key : keys){
		printf("%c = {", key);
		int cnt = 0;
		for(char val : sts[key-'A']){
			if(cnt++) printf(",");
			printf("%c", val);
		}
		printf("}\n");
	}
}