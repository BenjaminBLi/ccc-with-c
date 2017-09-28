#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i<N;i++)
using namespace std;

long long N, M, K;

int main(){
	scanf("%lld %lld %lld", &N, &M, &K);
	long long tmp = max(N, M);
	N = min(N, M);
	M = tmp;
	long long tot = N*M-2;
	//cout << (M-1+N-1-1) << endl;
	if(K >= M+N-3) printf("-1\n");
	else{
		long long tot;
		if(K == 0) printf("2\n");
		else if(K == 1) printf("4\n");
		else{
			K++;
			tot = 4;
			long long cInc = 2;
			int cnt = K/2;
			if(3+cnt <= M){
				tot = cnt*(4+(cnt-1));
				if(K&1) tot += 2+cnt;
				cout << tot << endl;
			}else{
				//cout << "YES" << endl;
				tot = M*(4+(M-1));
				cout << tot << endl;
			}
		}
	}
	return 0;
}