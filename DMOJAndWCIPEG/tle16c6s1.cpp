#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int T, N;
map<string, int> val;
string tmp;

int main(){
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		cin >> tmp;
		val[tmp] = i;
	}
	priority_queue<ii, vii, greater<ii>> pq;
	scanf("%d", &N);
	for(int i= 1; i <= N; i++){
		cin >> tmp;
		pq.push(ii(val[tmp], i));
	}
	while(!pq.empty()){
		ii curr = pq.top(); pq.pop();
		printf("%d\n", curr.second);
	}

	return 0;
}