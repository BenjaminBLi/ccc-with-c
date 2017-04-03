#include <bits/stdc++.h>
using namespace std;

int N, K, arr[510], pos[510], tri[510][510];
int mod = (int) 1e9+7;

int genTri(){
	for(int i = 0;i <= 500; i++){
		for(int j = 0;j <= i; j++){
			if(j == i || j == 0) tri[i][j] = 1;
			else{
				tri[i][j] = tri[i-1][j-1]%mod + tri[i-1][j]%mod;
				tri[i][j] %= mod;
			}
		}
	}
}

int main(){
	scanf("%d", &K);
	for(int c =0;c < K; c++) {
		//cout << c << endl;
		scanf("%d", arr+c);
	}
	genTri();
	int sz = 0;
	long long ans = 1;
	for(int i =0;i < K; i++){
		sz += arr[i];
		ans *= tri[sz-1][arr[i]-1]%mod;
		ans %= mod;
		//cout << sz << endl;
	}
	cout << ans << endl;

	return 0;
}