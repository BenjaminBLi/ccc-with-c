#include <bits/stdc++.h>
using namespace std;
typedef unsigned short us;
unsigned short memo[2][10010];
int N, M;
char a[10000], b[10000];

us min3(us &a, us &b, us &c){
	return min(a, min(b, c));
}

int main(){
	scanf("%d %d", &N, &M);
	//getchar();
	for(int i =0; i < N; i++) scanf(" %c", a+i);
	for(int i =0; i < M; i++) scanf(" %c", b+i);
	us best;
	for(int i =0 ; i <= N; i++){
		for(int j = 0; j <= M; j++){
			//cout << i << j << endl;
			if(i&1){
				if(i == 0 && j == 0) memo[1][j] = 0;
				else if(i == 0) memo[1][j] = j;
				else if (j == 0) memo[1][j] = i;
				else if(a[i-1] == b[j-1]) memo[1][j] = memo[0][j-1];
				else{
					memo[1][j] = 1+min3(memo[1][j-1], memo[0][j], memo[0][j-1]);
				}
			}else{
				if(i == 0 && j == 0) memo[0][j] = 0;
				else if(i == 0) memo[0][j] = j;
				else if (j == 0) memo[0][j] = i;
				else if(a[i-1] == b[j-1]) memo[0][j] = memo[1][j-1];
				else{
					memo[0][j] = 1+min3(memo[0][j-1], memo[1][j], memo[1][j-1]);
				}
			}
		}
	}

	long long tot = 0;
	int idx = N&1 ? 1 : 0;
	for(int i = 1; i < M; i++) {
		tot += memo[idx][i];
	}
	printf("%lld\n", tot);
	return 0;
}