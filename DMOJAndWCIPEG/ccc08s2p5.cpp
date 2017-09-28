#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i < N; i++)
using namespace std;

int N, sum, sz[110],  V[110], cnt[5000010];
bool memo[5000010];
long long total, half;
int main(){
	scanf("%d", &N);
	sum = 0;
	fori(i, N){
		scanf("%d %d", &sz[i], &V[i]);
		total += 1LL*sz[i]*V[i];
		//cnt += sz[i];
	}
	half = total/2;
	//cout << half << endl;
	memset(memo, false, sizeof(memo));
	memo[0] = true;
	fori(i, N) {
		memset(cnt, 0, sizeof(cnt));
		for(int j = V[i]; j <= half; j++){
			if(memo[j]) continue;
			if(memo[j-V[i]]){
				if(cnt[j-V[i]]+1 <= sz[i]) {
					memo[j] = true;
					cnt[j] = cnt[j-V[i]]+1;
				}
			}
		}
		//fori(j, half+1) printf("%d, ", memo[j]); cout << endl;
		//fori(j, half+1) printf("%d, ", cnt[j]); cout << endl << endl;
	}
	int i;
	//cout << memo[126] << endl;
	for(i = half; i >= 0; i--){
		if(memo[i]){
			break;
		}
	}
	long long ans = total - i-i;
	cout << ans << endl;
	

	//cout << abs(other-memo[cnt]) << endl;
	return 0;
}