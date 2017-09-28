#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i < N; i++)
using namespace std;

int N, sum, sz[110], cnt, V[110];
long long total, half, memo[50010];
int main(){
	scanf("%d", &N);
	sum = 0;
	fori(i, N){
		scanf("%d %d", &sz[i], &V[i]);
		total += 1LL*sz[i]*V[i];
		cnt += sz[i];
	}
	half = total/2;

	fori(i, N) fori(j, sz[i]) for(int j = cnt; j >= 1; j--) {
		if(abs(half - (memo[j-1]+V[i])) <= abs(half-memo[j]))
			memo[j] = memo[j-1]+V[i];
		else
			memo[j] = memo[j];
	}
	int other = total - memo[cnt];

	cout << abs(other-memo[cnt]) << endl;
	return 0;
}