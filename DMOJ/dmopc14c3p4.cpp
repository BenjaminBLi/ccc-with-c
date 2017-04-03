#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, K, A, B, factors[100110];
vector<int> nF[100000];

void gen(){
	for(int i =0; i <= 100000; i++) factors[i] = 1;
	for(int i = 2; i <= 100000; i++){
		//cout << factors[i] << endl;
		for(int j = i; j <= 100000; j += i){
			factors[j]++;
		}
	}
}

int main(){
	scanf("%d", &T);
	gen();
	//for(int i = 1; i < 20; i++) printf("%d: %d, ", i, factors[i]); cout << endl;
	for(int i = 1; i <= 100000; i++){
		nF[factors[i]].push_back(i);
	}
	for(;T--;){
		scanf("%d %d %d", &K, &A, &B);
		auto iter = lower_bound(nF[K].begin(), nF[K].end(), A);
		if(iter == nF[K].end()){
			printf("0\n"); continue;
		}
		int idx1 = iter - nF[K].begin();

		iter = upper_bound(nF[K].begin(), nF[K].end(), B)-1;
		int idx2 = iter-nF[K].begin();
		if(nF[K][idx2] < A || nF[K][idx2] > B){
			printf("0\n");
			continue;
		}
		//printf("%d: %d to %d: %d\n", idx1, nF[K][idx1], idx2, nF[K][idx2]);
		printf("%d\n", idx2-idx1+1);
	}

	return 0;
}