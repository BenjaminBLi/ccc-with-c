#include <bits/stdc++.h>
#define fori(i, N) for(int i = 0; i < N; i++)
using namespace std;

int memo[3011][111][111][2], N, A[3011], M, B[111];

int solve(int pos, int l, int r, int can){
	//printf("%d %d %d %d\n", pos, l, r, can);
	int best;
	if(memo[pos][l][r][can] != -1) return memo[pos][l][r][can];
	if(pos == N+1) return 0;
	if(pos <= N){
		best = max(best, solve(pos+1, l, r, 1));
		if(can) best = max(best, solve(pos+1, l, r, 0)+A[pos]);
	}if(l <= r){
		best = max(best, solve(pos, l+1, r, 1));
		if(can) {
			best = max(best, solve(pos, l, r-1, 0)+B[r]);	
			//best = max(best, solve(pos, l+1, r, 0)+B[l]);
		}
	}
	//printf("%d\n", best);
	return memo[pos][l][r][can] = best;
}

int main(){
	scanf("%d", &N);
	fori(i, N) scanf("%d", &A[i+1]);
	scanf("%d", &M);
	fori(i, M) scanf("%d", &B[i+1]);
	sort(B+1, B+M+1);
	memset(memo, -1, sizeof(memo));
	//fori(i, N) printf("%d, ", A[i]); cout << endl;
	//fori(i, M) printf("%d, ", B[i]); cout << endl;
	cout << solve(1, 1, M, 1)<< endl;
	return 0;
}