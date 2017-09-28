#include <bits/stdc++.h>
using namespace std;

int K, N, D;

long long jacks[100010];

int main(){
	scanf("%d %d %d", &N, &K, &D);
	for(int i =0; i < 100010; i++) jacks[i] = 1;
	int curr = -1;

	char ch;
	long long a = 0;
	for(int i =0; i < N; i++){

		scanf(" %c", &ch);
		if(ch == 'T') curr++;
		else{
			scanf("%lld", &a);
			if(a && jacks[curr] && D/jacks[curr] < a) jacks[curr] = D+1;
			else jacks[curr] *= a;
		}
		//cout << curr << endl;
	}
	
	for(int i = curr-1; i >= 0; i--){
		//cout << D/jacks[i]/jacks[i-1] << endl;
		if(jacks[i] && jacks[i+1] && D/jacks[i]/jacks[i+1] < 1) jacks[i] = D+1;
		else jacks[i] *= jacks[i+1];
	}
	for(int i =0;i <= curr; i++){
		//cout << jacks[i] << endl;
		if(jacks[i] > D) printf("dust\n");
		else printf("%lld\n", jacks[i]);
	}

	return 0;
}