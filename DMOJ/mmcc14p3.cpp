#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i < N; i++)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi tree[5010];

int N, S, a, b, maxH, ansV, curr, best, sz, pre[5010];
bool v[5010], cov[5010];

void dfs(int curr){
	sz++; v[curr] = true;
	for(int n : tree[curr]) if(!v[n]) dfs(n);
	if(sz > maxH){
		maxH = sz;
		ansV = curr;
	}
	sz--;
}

void bfs(int start){
	queue<int> q;
	memset(v, false, sizeof(v));
	q.push(start);
	pre[start] = start;
	curr = -1;
	while(!q.empty()){
		//cout << curr << endl;
		curr = q.front(); q.pop();
		v[curr] = true;
		for(int n : tree[curr]){
			if(!v[n]){
				pre[n] = curr;
				q.push(n);	
			}
		}	
	}
}

void cover(int &maxSz, int &c){
	//cout << c << endl;
	cov[c] = true;
	if(sz < maxSz){
		sz++;
		for(int n : tree[c]){
			if(!cov[n]) cover(maxSz, n);
		}
		sz--;
	}
}

bool valid(int maxSz){
	int c = curr;
	int cnt = 0;
	memset(cov, false, sizeof(c));
	//printf("SIZE: %d\n", maxSz);
	while(c != ansV && pre[c] != c){
		//cout << c+1 << endl;
		fori(i, maxSz) {
			if(!cov[c]){
				cover(maxSz, c);
				cnt++;
			}
			c = pre[c];
		}
		//cout << c << endl;
	}
	//cout << endl;
	return cnt <= S;
}

int bfind(){
	//last = curr...
	int hi = maxH, lo = 1, mid;
	while(hi > lo){
		//cout << "YES" << endl;
		mid = (hi+lo+1)/2;
		//printf("%d, %d, %d\n", hi, mid, lo);
		if(valid(mid)) hi = mid-1;
		else lo = mid;
	}
	return mid;
}


int main(){
	scanf("%d %d", &N, &S);
	if(S >= N) cout << 0 << endl;
	else{
		fori(i, N-1){
			scanf("%d %d", &a, &b);
			a--; b--;
			tree[a].push_back(b); tree[b].push_back(a);
		}	
		dfs(a);
		memset(v, false, sizeof(v)); sz = 0; b = ansV;
		//cout << b << endl;
		dfs(ansV);
		bfs(ansV);
		//cout << valid(2) << endl;
		cout << bfind() << endl;
	}
}