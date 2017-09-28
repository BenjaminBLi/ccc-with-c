#include <bits/stdc++.h>
using namespace std;

int N, M, memo[1010][1010];
char str1[1010], str2[1010];

int min3(int x, int y, int z){
	return min(x, min(y, z));
}

int main(){
	scanf("%d %d", &N, &M);
	//getchar();
	for(int i = 0; i < N; i++) scanf(" %c", str1+i);
	//getchar();
	for(int i =0; i <= M; i++) scanf(" %c", str2+i);
	for(int i =0; i <= N; i++){
		for(int j = 0; j <= M; j++){
			if(i == 0) {
				memo[i][j] = j;
				if(j >= 2) memo[i][j] = min(memo[i][j], 1+memo[i][j-2]);
				if(j >= 3) memo[i][j] = min(memo[i][j], 1+memo[i][j-3]);
			}
			else if (j == 0) {
				memo[i][j] = i;
				if(i >= 2) memo[i][j] = min(memo[i][j], 1+memo[i-2][j]);
				if(i >= 3) memo[i][j] = min(memo[i][j], 1+memo[i-3][j]);
			}
			else if(str1[i-1] == str2[j-1]) {
				//printf("%d %d\n", i, j);
				memo[i][j] = memo[i-1][j-1];
			}
			else {
				memo[i][j] = min3(memo[i][j-1], memo[i-1][j], memo[i-1][j-1]);
				if(i >= 2) memo[i][j] = min(memo[i][j], memo[i-2][j]);
				if(i >= 3) memo[i][j] = min(memo[i][j], memo[i-3][j]);
				if(j >= 2) memo[i][j] = min(memo[i][j], memo[i][j-2]);
				if(j >= 3) memo[i][j] = min(memo[i][j], memo[i][j-3]);
				memo[i][j]++;
			}
		}
	}
	//for(int i =0; i <= N; i++) {for(int j =0; j <= M; j++) printf("%d, ", memo[i][j]); cout << endl;}
	printf("%d\n", memo[N][M]);
	return 0;
}