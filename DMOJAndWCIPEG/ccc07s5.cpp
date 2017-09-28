#include <bits/stdc++.h>
using namespace std;

int T, n, k, w, pins[30010], memo[510][30010];

int main(){
	scanf("%d", &T);
	//cout << "DONE" << endl;
	for(;T--;){
		scanf("%d %d %d", &n, &k, &w);
		memset(memo, 0, sizeof(memo)); memset(pins, 0, sizeof(pins));
		//scanf("%d", &pins[0]);
		//cout << "DONE" << endl;
		for(int i = 1; i <= n; i++) {
			//cout << i << endl;
			scanf("%d", &pins[i]);
			//printf("%d, ", pins[i]);
			memo[0][i] += pins[i] + memo[0][i-1];
			//printf("%d", pins[i-1]);
			if(i > w) memo[0][i] -= pins[i-w];
			//cout << endl;
		}
		//for(int i = 1; i <= n; i++) printf("%d, ", memo[0][i]); cout << endl;

		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= w; j++) memo[i][j] = memo[i-1][j];

			for(int j = w+1; j <= n; j++){
				if (i == 1) memo[i][j] = max(memo[i][j-1], memo[0][j]);
				else memo[i][j] = max(memo[i-1][j-w]+memo[0][j], memo[i][j-1]);
			}
		}

		printf("%lld\n", memo[k][n]);
	}
	return 0;
}