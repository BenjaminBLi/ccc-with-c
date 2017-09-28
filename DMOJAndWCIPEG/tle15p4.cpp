#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long N;
long long MOD = 1000000013;
ll fast_power(int a, ll b) {
 	if( !b ) return 1;

 	ll res = fast_power(a, b / 2)%MOD;
  	res *= res;
  	res %= MOD;

	if( b % 2 ) res *= a%MOD;
  	res %= MOD;

  	return res;
}

int main(){
	scanf("%lld", &N);
	if(N == 1) printf("1");

	else{
		long long ret;
		if((N%8)&1){
			long long exp = (N+1)/2;
			long long sign = 1;
			if(N%8 == 3 || N%8 == 5) sign = -1;
			long long ret = fast_power(2, N-2);
			ret += 1LL*sign*fast_power(2, exp-2);
			ret %= MOD;
			//cout << "YES" << endl;
			printf("%lld\n", (MOD+ret)%MOD);
		}else{
			//cout << "YES" << endl;
			long long sign = 1;
			//cout << (N%8) << endl;
			if((N%8) == 0) sign = 1;
			else if(N%8 == 2 || N%8 == 6) sign = 0;
			else sign = -1;
			ret = fast_power(2, N-2);
			ret += 1LL*sign*fast_power(2, N/2-1);
			ret %= MOD;
			//cout << sign << endl;
			//cout << (sign*(1<<(exp/2))/2) << endl;
			printf("%lld\n", (MOD+ret)%MOD);
		}
	}

	return 0;
}