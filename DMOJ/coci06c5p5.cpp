#include <bits/stdc++.h>
using namespace std;

int N, num[210], memo[210][210];

int solve(int l, int r){
	//cout << l << ", " << r << endl;
	if(l == r) return memo[l][r] = num[l]&1;
	if(memo[l][r] != -1000) return memo[l][r];
	int best = memo[l][l] - solve(l+1, r);
	//cout << best << endl;
	best = max(best, memo[r][r] -solve(l, r-1));

	return memo[l][r] = best;
}

int main(){
	scanf("%d", &N);
	memset(memo, -1000, sizeof(memo));
	for(int i =0; i < N; i++) {
		scanf("%d", num+i);
		num[i+N] = num[i];
		memo[i][i] = num[i]&1;
		memo[i+N][i+N] = num[i]&1;
	}
	for(int i =0; i < N<<1; i++) for(int j = i; j < N<<1; j++) {
		if(i == j) continue;
		memo[i][j] = -1000;
	}
	//for(int i =0; i < N<<1; i++) printf("%d, ", memo[i][i]); cout << endl;
	int cnt =0;
	for(int i =0; i < N; i++){
		//cout << memo[i][i] << endl;
		if(memo[i][i] - solve(i+1, i-1+N) > 0) cnt++;
	}
	cout << cnt << endl;

	return 0;
}