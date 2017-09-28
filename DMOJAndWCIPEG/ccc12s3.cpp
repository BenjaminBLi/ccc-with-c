#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int N, R, freq[1010];

int main(){
	scanf("%d", &N);
	for(int i =0; i < N; i++){
		scanf("%d", &R);
		freq[R]++;
	}
	priority_queue<ii> pq;
	for(int i = 1; i <= 1000; i++){
		pq.push(ii(freq[i], i));
	}
	int best = 0, bfreq = pq.top().first, bval = pq.top().second;
	pq.pop(); 
	int b2freq = pq.top().first, b2val = pq.top().second;

	while(pq.top().first >= b2freq){
		b2freq = pq.top().first, b2val = pq.top().second; pq.pop();
		best = max(best, abs(bval-b2val));
	}
	cout << best << endl;
	return 0;
}