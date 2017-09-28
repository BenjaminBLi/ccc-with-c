#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
/*
for(int i =1; i <= N; i++){
	dp[i][l] = min(dp[i][l], 1+dp[i-1][l]);
	dp[i][r] = min(dp[i][r], 1+dp[i-1][r]);
	for(int j = i-1; j >= 1; j--){
		if(can reach) dp[j][l] = min(dp[i][l], dp[j][l]);
	}
	for(int j = i+1; j <= N; j++)
		if(i hit j) dp[j][r] = min(dp[j][r], dp[i][r]);
}
*/

int N, memo[1010][2];
ii trees[1010];

int main(){
	scanf("%d", &N);
	int x, h;
	for(int i = 1; i <= N; i++) {
		scanf("%d %d", &x, &h);
		trees[i] = ii(x, h);
	}
	sort(trees+1, trees+N+1);
	//for(ii t : trees)printf("(%d, %d), ", t.first, t.second);
	memset(memo, 0x3f3f3f, sizeof(memo));
	memo[N][0] = 1; memo[1][1] = 1; memo[0][1] = 1;
	for(int i = 1; i <= N; i++){
		memo[N-i+1][0] = min(memo[N-i+1][0], 1+memo[N-i+2][0]);
		memo[i][1] = min(memo[i][1], 1+memo[i-1][1]);
		for(int j = N-i; j >= 1; j--){
			if(trees[j].first >= trees[N-i+1].first-trees[N-i+1].second && 
				trees[j].first <= trees[N-i+1].first-1) {
				memo[j][0] = min(memo[N+1-i][0], memo[j][0]);
			}
		}
		for(int j = i+1; j <= N; j++){
			if(trees[j].first >= trees[i].first+1 &&
			   trees[j].first <= trees[i].first+trees[i].second) memo[j][1] = min(memo[j][1], memo[i][1]);
		}
	}
	
	//for(int i = 1; i <= N; i++) printf("%d, ", memo[i][0]); cout << endl;
	//for(int i = 1; i <= N; i++) printf("%d, ", memo[i][1]); cout << endl;
	cout << min(memo[1][0], memo[N][1]) << endl;
	return 0;
}