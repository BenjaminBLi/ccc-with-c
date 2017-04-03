#include <bits/stdc++.h>
using namespace std;

int W[1010], V[1010], C, M, N, K, memo[1010];

int main(){
	scanf("%d %d", &C, &M);
	for(int i =0; i < C; i++){
		scanf("%d %d", &N, &K);
		W[i] = K;
		V[i] = N;
	}

	for(int i = 0; i < C; i++){
		for(int j = M; j >= W[i]; j--){
			memo[j] = max(memo[j], memo[j-W[i]]+V[i]);
		}
	}
	cout << memo[M] << endl;
	return 0;
}