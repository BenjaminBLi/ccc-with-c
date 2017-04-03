#include <bits/stdc++.h>
using namespace std;

int dist, N, a[32], memo[5390];

int main(){
	scanf("%d %d", &dist, &N);
	for(int i =0; i < N; i++) scanf("%d",a+i);

	memset(memo, 0x3f3f3f, sizeof(memo));
	memo[0] = 0;
	for(int i = 0; i <= dist; i++){
		for(int j =0; j < N; j++){
			memo[i+a[j]] = min(memo[i+a[j]], memo[i]+1);
		}
	}
	//for(int i =0;i <= dist; i++) printf("%d, ", memo[i]); cout << endl;
	//cout << memo[dist] << endl;
	if(memo[dist] >= 0x3f3f3f) printf("Roberta acknowledges defeat.\n");
	else printf("Roberta wins in %d strokes.\n", memo[dist]);

	return 0;
}