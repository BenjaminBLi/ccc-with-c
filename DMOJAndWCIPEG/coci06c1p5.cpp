#include <bits/stdc++.h>
using namespace std;

int N, jim[30][30];
double arr[30][30], memo[1048580];

double solve(int idx, int mask){

	if(mask == (1<<N)-1) return 1.0;

	if(memo[mask] != -1.0) return memo[mask];

	double best = 0.0;
	for(int i= 0; i < N; i++){
		if(mask&(1<<i)) continue;
		best = max(best, arr[idx][i]*solve(idx+1, mask | (1<<i)));
	}
	return memo[mask] = best;
}

int main(){
	scanf("%d", &N);
	fill(memo, memo+1048580, -1.0);
	for(int i =0; i < N; i++){
		for(int j =0; j < N; j++){
			scanf("%d", &jim[i][j]);
			arr[i][j] = jim[i][j];
			arr[i][j] /= 100;
		}
	}

	printf("%lf", 100*solve(0, 0));
	return 0;
}