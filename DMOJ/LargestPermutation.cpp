#include <bits/stdc++.h>
using namespace std;

int N, K, a[100010], idx[100010];

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++){
		scanf("%d", &a[i]);
		idx[a[i]] = i;
	}
	//int lim = min(N-1, K);
	for(int i = 1; i < N && K; i++){
		//search for N-i and swap with number at pos i
		if(a[i] == N-i+1) continue;
		int dest = idx[N-i+1];
		idx[a[i]] = dest;
		idx[N-i+1] = i;
		swap(a[dest], a[i]);
		K--;
	}
	for(int i = 1; i <= N; i++){
		if(i-1) printf(" ");
		printf("%d", a[i]);
	}
	return 0;
}